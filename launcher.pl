#!/usr/bin/perl

# Fichero para automatizacion de ejecucion por lotes, de un ejecutable,
# dados parametros de entrada.

$repetition = 1;
$path = "/home/sebastian/workspace-cs/matrix-multiplication-benchmark/";
@ejecutables = ("launcher.pl");
# @algorithms = ("1", "2", "3", "4", "5", "6", "7");
@algorithms = ("MM_Posix", "MM_OpenMP");

foreach $exe (@ejecutables){
    foreach $algorithm (@algorithms){
      print("$algorithm Start.\n");
      system("$path$algorithm/$exe");
      print("$algorithm Done.\n");
    }
}

exit(1);
