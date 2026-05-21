
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

b account_train 
set $bp1 = $bpnum

b functions_main
set $bp2 = $bpnum

commands $bp1
    printf "function that uses reference argument "
    diag1
    #layout split
end 

commands $bp2
    printf "main  function\n\n"
    diag1
end 


run
c
