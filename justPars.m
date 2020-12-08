selpath = uigetdir;
DirName = selpath;
%List files in folder
dinfo = dir(fullfile(DirName, '**\*_W_WY.wav'));
dinfo([dinfo.isdir]) = [];     %get rid of all directories including . and ..
nfiles = length(dinfo);

for j = 1 : nfiles
  filename = fullfile(dinfo(j).folder, dinfo(j).name);
  disp("File name = " + filename);
  fprintf("Processing file %d out of %d\n", j, nfiles);
  [filepath,name,ext] = fileparts(filename);
  disp("File path = " + filepath);
  
  command = "AcouPar_pu_x64.exe " + filename;
  fprintf("%s\n", command);
  [status, results] = system(command);
end