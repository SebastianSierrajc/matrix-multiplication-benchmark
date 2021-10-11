#!/usr/bin/perl

# Fichero para automatizacion de ejecucion por lotes, de un ejecutable,
# dados parametros de entrada.

$repetition = 1;
$path = "./algorithm";
@ejecutables = ("launcher.pl");
@algorithms = ("4", "5", "6", "7");

foreach $exe (@ejecutables){
    foreach $algorithm (@algorithms){
      print("algorithm-$algorithm Start.\n");
      system("./$path$algorithm/$exe");
      print("algorithm-$algorithm Done.\n");
    }
}

exit(1);
