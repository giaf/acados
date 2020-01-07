/*
 * Copyright 2019 Gianluca Frison, Dimitris Kouzoupis, Robin Verschueren,
 * Andrea Zanelli, Niels van Duijkeren, Jonathan Frey, Tommaso Sartor,
 * Branimir Novoselnik, Rien Quirynen, Rezart Qelibari, Dang Doan,
 * Jonas Koenemann, Yutao Chen, Tobias Schöls, Jonas Schlagenhauf, Moritz Diehl
 *
 * This file is part of acados.
 *
 * The 2-Clause BSD License
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.;
 */

#define S_FUNCTION_NAME   acados_sim_solver_sfunction_{{ model.name }}
#define S_FUNCTION_LEVEL  2

#define MDL_START

// acados
#include "acados/utils/print.h"
#include "acados_c/ocp_nlp_interface.h"
#include "acados_c/external_function_interface.h"

// example specific
#include "{{ model.name }}_model/{{ model.name }}_model.h"
#include "acados_sim_solver_{{ model.name }}.h"

#include "simstruc.h"

#define SAMPLINGTIME -1

// ** global data **
sim_config  *{{ model.name }}_sim_config;
sim_in      *{{ model.name }}_sim_in;
sim_out     *{{ model.name }}_sim_out;
void        *{{ model.name }}_sim_dims;
sim_opts    *{{ model.name }}_sim_opts;
sim_solver  *{{ model.name }}_sim_solver;


{% if solver_options.integrator_type == "ERK" %}
external_function_param_casadi * sim_forw_vde_casadi;
external_function_param_casadi * sim_expl_ode_fun_casadi;
{% if solver_options.hessian_approx == "EXACT" %}
// note: not used for simulation.
external_function_param_casadi * sim_hess_vde_casadi;
{% endif %}
{% elif solver_options.integrator_type == "IRK" %}
external_function_param_casadi * sim_impl_dae_fun;
external_function_param_casadi * sim_impl_dae_fun_jac_x_xdot_z;
external_function_param_casadi * sim_impl_dae_jac_x_xdot_u_z;
{% endif %}

static void mdlInitializeSizes (SimStruct *S)
{
    // specify the number of continuous and discrete states
    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    {# compute number of input ports #}
    {%- set n_inputs = 1 %}  {# x0 #}
    {%- if dims.nu > 0 %}  {# u0 -#}
        {%- set n_inputs = n_inputs + 1 -%}
    {%- endif %}
    {%- if dims.np > 0 %}  {# parameters #}
        {%- set n_inputs = n_inputs + 1 -%}
    {%- endif %}

    // specify the number of input ports
    if ( !ssSetNumInputPorts(S, {{ n_inputs }}) )
        return;

    // specify the number of output ports
    if ( !ssSetNumOutputPorts(S, 1) )
        return;

    // specify dimension information for the input ports
    {%- set i_input = 0 %}
    // x0
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.nx }});

    {%- if dims.nu > 0 %}
    {%- set i_input = i_input + 1 %}
    // u0
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.nu }});
    {%- endif %}

    {%- if dims.np > 0 %}
    {%- set i_input = i_input + 1 %}
    // parameters
    ssSetInputPortVectorDimension(S, {{ i_input }}, {{ dims.np }});
    {%- endif %}

    // specify dimension information for the output ports
    ssSetOutputPortVectorDimension(S, 0, {{ dims.nx }} ); // xnext

    // specify the direct feedthrough status
    // should be set to 1 for all inputs used in mdlOutputs
    {%- for i in range(end=n_inputs) %}
    ssSetInputPortDirectFeedThrough(S, {{ i }}, 1);
    {%- endfor %}

    // one sample time
    ssSetNumSampleTimes(S, 1);
}


#if defined(MATLAB_MEX_FILE)

#define MDL_SET_INPUT_PORT_DIMENSION_INFO
#define MDL_SET_OUTPUT_PORT_DIMENSION_INFO

static void mdlSetInputPortDimensionInfo(SimStruct *S, int_T port, const DimsInfo_T *dimsInfo)
{
    if ( !ssSetInputPortDimensionInfo(S, port, dimsInfo) )
         return;
}

static void mdlSetOutputPortDimensionInfo(SimStruct *S, int_T port, const DimsInfo_T *dimsInfo)
{
    if ( !ssSetOutputPortDimensionInfo(S, port, dimsInfo) )
         return;
}

#endif /* MATLAB_MEX_FILE */


static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, SAMPLINGTIME);
    ssSetOffsetTime(S, 0, 0.0);
}


static void mdlStart(SimStruct *S)
{
    {{ model.name }}_acados_sim_create();
}

static void mdlOutputs(SimStruct *S, int_T tid)
{
    InputRealPtrsType in_sign;
    {% set input_sizes = [dims.nx, dims.nu, dims.np] %}

    // local buffer
    {%- set buffer_size =  input_sizes | sort | last %}
    real_t buffer[{{ buffer_size }}];


    /* go through inputs */
    {%- set i_input = 0 %}
    // initial condition
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});
    for (int i = 0; i < {{ dims.nx }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    sim_in_set({{ model.name }}_sim_config, {{ model.name }}_sim_dims,
               {{ model.name }}_sim_in, "x", buffer);

{% if dims.nu > 0 %}
    // control input - u
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.nu }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    sim_in_set({{ model.name }}_sim_config, {{ model.name }}_sim_dims,
               {{ model.name }}_sim_in, "u", buffer);
{%- endif %}


{% if dims.np > 0 %}
    // parameters
    {%- set i_input = i_input + 1 %}
    in_sign = ssGetInputPortRealSignalPtrs(S, {{ i_input }});

    for (int i = 0; i < {{ dims.np }}; i++)
        buffer[i] = (double)(*in_sign[i]);

    // update value of parameters
    {{ model.name }}_acados_sim_update_params(ii, buffer, {{ dims.np }});
{%- endif %}


    /* call solver */
    int acados_status = {{ model.name }}_acados_sim_solve();


    /* set outputs */
    real_t *out_x = ssGetOutputPortRealSignal(S, 0);

    // extract solver info
    // get simulated state
    sim_out_get({{ model.name }}_sim_config, {{ model.name }}_sim_dims, {{ model.name }}_sim_out,
                "xn", (void *) out_x);

}


static void mdlTerminate(SimStruct *S)
{
    {{ model.name }}_acados_sim_free();
}


#ifdef  MATLAB_MEX_FILE
#include "simulink.c"
#else
#include "cg_sfun.h"
#endif