
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

commands $bp1
printf "arrays  function\n\n"
diag1
layout split
end 

run
si
si
p/x &array_int
p/x &array_f
s
s
#x/s $x8
#s
#x/s $x8
