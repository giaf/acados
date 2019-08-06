function C_ocp_ext_fun = ocp_set_ext_fun(C_ocp, C_ocp_ext_fun, model_struct, opts_struct)

model_name = model_struct.name;
N = opts_struct.param_scheme_N;

% get acados folder
acados_folder = getenv('ACADOS_INSTALL_DIR');
mex_flags = getenv('ACADOS_MEX_FLAGS');

% set paths
acados_mex_folder = fullfile(acados_folder, 'interfaces', 'acados_matlab');
acados_include = ['-I' acados_folder];
acados_interfaces_include = ['-I' fullfile(acados_folder, 'interfaces')];
external_include = ['-I' fullfile(acados_folder, 'external')];
blasfeo_include = ['-I' fullfile(acados_folder, 'external' , 'blasfeo', 'include')];
acados_lib_path = ['-L' fullfile(acados_folder, 'lib')];
acados_matlab_lib_path = ['-L' fullfile(acados_folder, 'interfaces', 'acados_matlab')];
model_lib_path = ['-L', opts_struct.output_dir];

%% select files to compile
%mex_files = {};
mex_files = {fullfile(acados_mex_folder, 'ocp_set_ext_fun_gen.c')};
setter = {};
set_fields = {};
mex_fields = {};
fun_names = {};
mex_names = {};
phase = {};
phase_start = {};
phase_end = {};

% dynamics
if (strcmp(model_struct.dyn_type, 'explicit'))

	setter = {setter{:} ...
		'ocp_nlp_dynamics_model_set' ...
		'ocp_nlp_dynamics_model_set' ...
		'ocp_nlp_dynamics_model_set' ...
		'ocp_nlp_dynamics_model_set' ...
		};
	set_fields = {set_fields{:} ...
		'expl_ode_fun' ...
		'expl_vde_for' ...
		'expl_vde_adj' ...
		'expl_ode_hes' ...
		};
	mex_fields = {mex_fields{:} ...
		'dyn_expl_ode_fun' ...
		'dyn_expl_vde_for' ...
		'dyn_expl_vde_adj' ...
		'dyn_expl_ode_hes' ...
		};
	fun_names = {fun_names{:} ...
		[model_name, '_dyn_expl_ode_fun'] ...
		[model_name, '_dyn_expl_vde_for'] ...
		[model_name, '_dyn_expl_vde_adj'] ...
		[model_name, '_dyn_expl_ode_hes'] ...
		};
	mex_names = {mex_names{:} ...
		[model_name, '_ocp_set_ext_fun_dyn_0_expl_ode_fun'] ...
		[model_name, '_ocp_set_ext_fun_dyn_0_expl_vde_for'] ...
		[model_name, '_ocp_set_ext_fun_dyn_0_expl_vde_adj'] ...
		[model_name, '_ocp_set_ext_fun_dyn_0_expl_ode_hes'] ...
		};
	phase = {phase{:}, 0, 0, 0, 0};
	phase_start = {phase_start{:}, 0, 0, 0, 0};
	phase_end = {phase_end{:}, N-1, N-1, N-1, N-1};

elseif (strcmp(model_struct.dyn_type, 'implicit'))

	if (strcmp(opts_struct.sim_method, 'irk'))

		setter = {setter{:} ...
			'ocp_nlp_dynamics_model_set' ...
			'ocp_nlp_dynamics_model_set' ...
			'ocp_nlp_dynamics_model_set' ...
			'ocp_nlp_dynamics_model_set' ...
			};
		set_fields = {set_fields{:} ...
			'impl_ode_fun' ...
			'impl_ode_fun_jac_x_xdot' ...
			'impl_ode_jac_x_xdot_u' ...
			'impl_ode_hess' ...
			};
		mex_fields = {mex_fields{:} ...
			'dyn_impl_ode_fun' ...
			'dyn_impl_ode_fun_jac_x_xdot' ...
			'dyn_impl_ode_jac_x_xdot_u' ...
			'dyn_impl_ode_hess' ...
			};
		fun_names = {fun_names{:} ...
			[model_name, '_dyn_impl_ode_fun'] ...
			[model_name, '_dyn_impl_ode_fun_jac_x_xdot'] ...
			[model_name, '_dyn_impl_ode_jac_x_xdot_u'] ...
			[model_name, '_dyn_impl_ode_hess'] ...
			};
		mex_names = {mex_names{:} ...
			[model_name, '_ocp_set_ext_fun_dyn_0_impl_ode_fun'] ...
			[model_name, '_ocp_set_ext_fun_dyn_0_impl_ode_fun_jac_x_xdot'] ...
			[model_name, '_ocp_set_ext_fun_dyn_0_impl_ode_jac_x_xdot_u'] ...
			[model_name, '_ocp_set_ext_fun_dyn_0_impl_ode_hess'] ...
			};
		phase = {phase{:}, 0, 0, 0, 0};
		phase_start = {phase_start{:}, 0, 0, 0, 0};
		phase_end = {phase_end{:}, N-1, N-1, N-1, N-1};

	elseif (strcmp(opts_struct.sim_method, 'irk_gnsf'))

		setter = {setter{:} ...
			'ocp_nlp_dynamics_model_set' ...
			'ocp_nlp_dynamics_model_set' ...
			'ocp_nlp_dynamics_model_set' ...
			'ocp_nlp_dynamics_model_set' ...
			'ocp_nlp_dynamics_model_set' ...
			};
		set_fields = {set_fields{:} ...
			'gnsf_f_lo_fun_jac_x1k1uz' ...
			'gnsf_get_matrices_fun' ...
			'gnsf_phi_fun' ...
			'gnsf_phi_fun_jac_y' ...
			'gnsf_phi_jac_y_uhat' ...
			};
		mex_fields = {mex_fields{:} ...
			'dyn_gnsf_f_lo_fun_jac_x1k1uz' ...
			'dyn_gnsf_get_matrices_fun' ...
			'dyn_gnsf_phi_fun' ...
			'dyn_gnsf_phi_fun_jac_y' ...
			'dyn_gnsf_phi_jac_y_uhat' ...
			};
		fun_names = {fun_names{:} ...
			[model_name, '_dyn_gnsf_f_lo_fun_jac_x1k1uz'] ...
			[model_name, '_dyn_gnsf_get_matrices_fun'] ...
			[model_name, '_dyn_gnsf_phi_fun'] ...
			[model_name, '_dyn_gnsf_phi_fun_jac_y'] ...
			[model_name, '_dyn_gnsf_phi_jac_y_uhat'] ...
			};
		mex_names = {mex_names{:} ...
			[model_name, '_ocp_set_ext_fun_dyn_0_gnsf_f_lo_fun_jac_x1k1uz'] ...
			[model_name, '_ocp_set_ext_fun_dyn_0_gnsf_get_matrices_fun'] ...
			[model_name, '_ocp_set_ext_fun_dyn_0_gnsf_phi_fun'] ...
			[model_name, '_ocp_set_ext_fun_dyn_0_gnsf_phi_fun_jac_y'] ...
			[model_name, '_ocp_set_ext_fun_dyn_0_gnsf_phi_jac_y_uhat'] ...
			};
		phase = {phase{:}, 0, 0, 0, 0, 0};
		phase_start = {phase_start{:}, 0, 0, 0, 0, 0};
		phase_end = {phase_end{:}, N-1, N-1, N-1, N-1, N-1};

	else
		fprintf('\nocp_set_ext_fun: sim_method not supported: %s\n', opts_struct.sim_method);
	end

elseif (strcmp(model_struct.dyn_type, 'discrete'))

	setter = {setter{:} ...
		'ocp_nlp_dynamics_model_set' ...
		'ocp_nlp_dynamics_model_set' ...
		};
	set_fields = {set_fields{:} ...
		'disc_dyn_fun_jac' ...
		'disc_dyn_fun_jac_hess' ...
		};
	mex_fields = {mex_fields{:} ...
		'dyn_disc_phi_fun_jac' ...
		'dyn_disc_phi_fun_jac_hess' ...
		};
	fun_names = {fun_names{:} ...
		[model_name, '_dyn_disc_phi_fun_jac'] ...
		[model_name, '_dyn_disc_phi_fun_jac_hess'] ...
		};
	mex_names = {mex_names{:} ...
		[model_name, '_ocp_set_ext_fun_dyn_0_disc_phi_fun_jac'] ...
		[model_name, '_ocp_set_ext_fun_dyn_0_disc_phi_fun_jac_hess'] ...
		};
	phase = {phase{:}, 0, 0};
	phase_start = {phase_start{:}, 0, 0};
	phase_end = {phase_end{:}, N-1, N-1};

else
	fprintf('\nocp_compile_mex_mode_dep: dyn_type not supported: %s\n', model_struct.dyn_type);
end

% nonlinear constraints
if (strcmp(model_struct.constr_type, 'bgh') && (isfield(model_struct, 'dim_nh') && model_struct.dim_nh>0))

	setter = {setter{:} ...
		'ocp_nlp_constraints_model_set' ...
		'ocp_nlp_constraints_model_set' ...
		};
	set_fields = {set_fields{:} ...
		'nl_constr_h_fun_jac' ...
		'nl_constr_h_fun_jac_hess' ...
		};
	mex_fields = {mex_fields{:} ...
		'constr_h_fun_jac_ut_xt' ...
		'constr_h_fun_jac_ut_xt_hess' ...
		};
	fun_names = {fun_names{:} ...
		[model_name, '_constr_h_fun_jac_ut_xt'] ...
		[model_name, '_constr_h_fun_jac_ut_xt_hess'] ...
		};
	mex_names = {mex_names{:} ...
		[model_name, '_ocp_set_ext_fun_constr_0_h_fun_jac_ut_xt'] ...
		[model_name, '_ocp_set_ext_fun_constr_0_h_fun_jac_ut_xt_hess'] ...
		};
	phase = {phase{:}, 0, 0};
	phase_start = {phase_start{:}, 0, 0};
	phase_end = {phase_end{:}, N-1, N-1};

end
if (strcmp(model_struct.constr_type, 'bgh') && (isfield(model_struct, 'dim_nh_e') && model_struct.dim_nh_e>0))

	setter = {setter{:} ...
		'ocp_nlp_constraints_model_set' ...
		'ocp_nlp_constraints_model_set' ...
		};
	set_fields = {set_fields{:} ...
		'nl_constr_h_fun_jac' ...
		'nl_constr_h_fun_jac_hess' ...
		};
	mex_fields = {mex_fields{:} ...
		'constr_h_fun_jac_ut_xt' ...
		'constr_h_fun_jac_ut_xt_hess' ...
		};
	fun_names = {fun_names{:} ...
		[model_name, '_constr_h_e_fun_jac_ut_xt'] ...
		[model_name, '_constr_h_e_fun_jac_ut_xt_hess'] ...
		};
	mex_names = {mex_names{:} ...
		[model_name, '_ocp_set_ext_fun_constr_1_h_fun_jac_ut_xt'] ...
		[model_name, '_ocp_set_ext_fun_constr_1_h_fun_jac_ut_xt_hess'] ...
		};
	phase = {phase{:}, 1, 1};
	phase_start = {phase_start{:}, N, N};
	phase_end = {phase_end{:}, N, N};

end
% nonlinear least squares
if (strcmp(model_struct.cost_type, 'nonlinear_ls'))

	setter = {setter{:} ...
		'ocp_nlp_cost_model_set' ...
		'ocp_nlp_cost_model_set' ...
		};
	set_fields = {set_fields{:} ...
		'nls_res_jac' ...
		'nls_hess' ...
		};
	mex_fields = {mex_fields{:} ...
		'cost_y_fun_jac_ut_xt' ...
		'cost_y_hess' ...
		};
	fun_names = {fun_names{:} ...
		[model_name, '_cost_y_fun_jac_ut_xt'] ...
		[model_name, '_cost_y_hess'] ...
		};
	mex_names = {mex_names{:} ...
		[model_name, '_ocp_set_ext_fun_cost_0_y_fun_jac_ut_xt'] ...
		[model_name, '_ocp_set_ext_fun_cost_0_y_hess'] ...
		};
	phase = {phase{:}, 0, 0};
	phase_start = {phase_start{:}, 0, 0};
	phase_end = {phase_end{:}, N-1, N-1};

end
if (strcmp(model_struct.cost_type_e, 'nonlinear_ls'))

	setter = {setter{:} ...
		'ocp_nlp_cost_model_set' ...
		'ocp_nlp_cost_model_set' ...
		};
	set_fields = {set_fields{:} ...
		'nls_res_jac' ...
		'nls_hess' ...
		};
	mex_fields = {mex_fields{:} ...
		'cost_y_fun_jac_ut_xt' ...
		'cost_y_hess' ...
		};
	fun_names = {fun_names{:} ...
		[model_name, '_cost_y_e_fun_jac_ut_xt'] ...
		[model_name, '_cost_y_e_hess'] ...
		};
	mex_names = {mex_names{:} ...
		[model_name, '_ocp_set_ext_fun_cost_1_y_fun_jac_ut_xt'] ...
		[model_name, '_ocp_set_ext_fun_cost_1_y_hess'] ...
		};
	phase = {phase{:}, 1, 1};
	phase_start = {phase_start{:}, N, N};
	phase_end = {phase_end{:}, N, N};

end
% external cost
if (strcmp(model_struct.cost_type, 'ext_cost'))

	setter = {setter{:} ...
		'ocp_nlp_cost_model_set' ...
		};
	set_fields = {set_fields{:} ...
		'ext_cost_jac_hes' ...
		};
	mex_fields = {mex_fields{:} ...
		'cost_ext_cost_jac_hes' ...
		};
	fun_names = {fun_names{:} ...
		[model_name, '_cost_ext_cost_jac_hes'] ...
		};
	mex_names = {mex_names{:} ...
		[model_name, '_ocp_set_ext_fun_cost_0_ext_cost_jac_hes'] ...
		};
	phase = {phase{:}, 0};
	phase_start = {phase_start{:}, 0};
	phase_end = {phase_end{:}, N-1};

end
if (strcmp(model_struct.cost_type_e, 'ext_cost'))

	setter = {setter{:} ...
		'ocp_nlp_cost_model_set' ...
		};
	set_fields = {set_fields{:} ...
		'ext_cost_jac_hes' ...
		};
	mex_fields = {mex_fields{:} ...
		'cost_ext_cost_jac_hes' ...
		};
	fun_names = {fun_names{:} ...
		[model_name, '_cost_ext_cost_e_jac_hes'] ...
		};
	mex_names = {mex_names{:} ...
		[model_name, '_ocp_set_ext_fun_cost_1_ext_cost_jac_hes'] ...
		};
	phase = {phase{:}, 1};
	phase_start = {phase_start{:}, N};
	phase_end = {phase_end{:}, N};

end

% compile mex files
%mex_files
%setter
%set_fields
%mex_fields
%fun_names
%mex_names
%phase
%phase_start
%phase_end
if (strcmp(opts_struct.compile_mex, 'true'))

	if is_octave()
		if exist(fullfile(opts_struct.output_dir, 'cflags_octave.txt'), 'file')==0
		diary(fullfile(opts_struct.output_dir, 'cflags_octave.txt'))
			diary on
			mkoctfile -p CFLAGS
			diary off
			input_file = fopen(fullfile(opts_struct.output_dir, 'cflags_octave.txt'), 'r');
			cflags_tmp = fscanf(input_file, '%[^\n]s');
			fclose(input_file);
			cflags_tmp = [cflags_tmp, ' -std=c99 -fopenmp'];
			input_file = fopen(fullfile(opts_struct.output_dir, 'cflags_octave.txt'), 'w');
			fprintf(input_file, '%s', cflags_tmp);
			fclose(input_file);
		end
%		input_file = fopen('build/cflags_octave.txt', 'r');
%		cflags_tmp = fscanf(input_file, '%[^\n]s');
%		fclose(input_file);
%		setenv('CFLAGS', cflags_tmp);
	end

	%% get pointers for external functions in model
	for ii=1:length(mex_names)

		disp(['compiling ', mex_names{ii}])
		if is_octave()
	%		mkoctfile -p CFLAGS
			input_file = fopen(fullfile(opts_struct.output_dir, 'cflags_octave.txt'), 'r');
			cflags_tmp = fscanf(input_file, '%[^\n]s');
			fclose(input_file);
			cflags_tmp = [cflags_tmp, ' -DSETTER=', setter{ii}];
			cflags_tmp = [cflags_tmp, ' -DSET_FIELD=', set_fields{ii}];
			cflags_tmp = [cflags_tmp, ' -DMEX_FIELD=', mex_fields{ii}];
			cflags_tmp = [cflags_tmp, ' -DFUN_NAME=', fun_names{ii}];
			cflags_tmp = [cflags_tmp, ' -DPHASE=', num2str(phase{ii})];
			cflags_tmp = [cflags_tmp, ' -DN0=', num2str(phase_start{ii})];
			cflags_tmp = [cflags_tmp, ' -DN1=', num2str(phase_end{ii})];
			setenv('CFLAGS', cflags_tmp);
			mex(acados_include, acados_interfaces_include, external_include, blasfeo_include, acados_lib_path, acados_matlab_lib_path, model_lib_path, '-lacados', '-lhpipm', '-lblasfeo', ['-l', model_name], mex_files{1});
		else
			mex(mex_flags, 'CFLAGS=$CFLAGS -std=c99 -fopenmp', ['-DSETTER=', setter{ii}], ['-DSET_FIELD=', set_fields{ii}], ['-DMEX_FIELD=', mex_fields{ii}], ['-DFUN_NAME=', fun_names{ii}], ['-DPHASE=', num2str(phase{ii})], ['-DN0=', num2str(phase_start{ii})], ['-DN1=', num2str(phase_end{ii})], acados_include, acados_interfaces_include, external_include, blasfeo_include, acados_lib_path, acados_matlab_lib_path, model_lib_path, '-lacados', '-lhpipm', '-lblasfeo', ['-l', model_name], mex_files{1}); % TODO
		end
		
%		clear(mex_names{ii})
		movefile(['ocp_set_ext_fun_gen.', mexext], fullfile(opts_struct.output_dir, [mex_names{ii}, '.', mexext]));
	end
	
	if is_octave()
		movefile('*.o', opts_struct.output_dir);
	end

end

%C_ocp_ext_fun

% codegen the file to call mex files
%fileID = fopen('build/ocp_set_ext_fun_tmp.m', 'w');
%fprintf(fileID, 'function C_ocp_ext_fun = ocp_set_ext_fun_tmp(C_ocp, C_ocp_ext_fun, model_struct, opts_struct)\n');
for ii=1:length(mex_names)
	C_ocp_ext_fun = eval([mex_names{ii}, '(C_ocp, C_ocp_ext_fun, model_struct, opts_struct)']);
%	fprintf(fileID, [mex_names{ii}, '(C_ocp, C_ocp_ext_fun, model_struct, opts_struct);\n']);
end
%fclose(fileID);

% call mex files
%ocp_set_ext_fun_tmp(C_ocp, C_ocp_ext_fun, model_struct, opts_struct);

%C_ocp_ext_fun
%keyboard

return;

