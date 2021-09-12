#!/usr/bin/perl

# Fichero para automatizacion de ejecucion por lotes, de un ejecutable,
# dados parametros de entrada.

$repetition = 30;
$path = "./";
@ejecutables = ("matrixAPP");
@matrixSize = ("100", "200", "400", "800", "1000", "1200", "2000", "4000");
@threads = ("1", "2", "4", "8");

foreach $exe (@ejecutables){
    foreach $size (@matrixSize){
        foreach $thread (@threads){
            $fichero = "$path"."outputs/$exe-size$size-T$thread.txt";
            for($i = 0; $i < $repetition; $i++){
                system("$path$exe.out $size $thread >> $fichero\n");
            }
            print("$exe-size$size-T$thread DONE.\n");
        }
    }
}

exit(1);

