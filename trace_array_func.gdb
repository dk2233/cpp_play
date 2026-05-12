
# Nie wyświetlamy potwierdzeń przy przeładowaniu
set confirm off
#do we need to see every commands?
set trace-command off

define diag1
    printf "--- Diagnostyka Funkcji ---\n"
    # Wyświetla adres i plik/linię
    i args
    info line
     frame
     where 3
    disassemble $pc, +20 
    printf "Adres w rejestrze PC: %p\n", $pc
    printf "---------------------------\n"
end

b arrays_tests
set $bp1 = $bpnum


b set_array
set $bp2 = $bpnum

commands $bp1
printf "arrays  function\n\n"
diag1
p/x &array_int
set $addr=&array_int
end 

commands $bp2
    printf "\narray set test function\nto test how array argument is handled\n\n"
    diag1
    #layout split
end 

run
c
p/x a
printf "address of array_int %p argument of this function %p\n", $addr, a
printf "using of address argument does not copy whole array to function \n"

fin
n
n 
printf "address of span array %p \n",&span_int2
set $addr=&span_int2 
si 
si 
si 
si 
si 
diag1
printf "\na_span at the beginning \n different data than original span means - it has to be copied\n"
p a_span

c

printf "address of span argument of function %p compare with %p - different means data was copied ", &a_span, $addr
#x/s $x8
#s
#x/s $x8
