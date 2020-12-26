% Adriano Farina - xorgol@gmail.com - 2020
% Asks user for a path, then transverses every subfolder and passes every
% file matching the filename pattern to AcouPar, which stores all the
% values for ISO3382 acoustical parameters in acoupar_pu.txt

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