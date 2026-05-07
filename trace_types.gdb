# Nie wyświetlamy potwierdzeń przy przeładowaniu
set confirm off

define diag1
    printf "--- Diagnostyka Funkcji ---\n"
    # Wyświetla adres i plik/linię
    i args
    info line
     frame
    disassemble $pc, +20 
    printf "Adres w rejestrze PC: %p\n", $pc
    printf "---------------------------\n"
end

# Ustawiamy breakpoint na funkcji (zmień 'moja_funkcja' na docelową)
break types_test

# Definiujemy listę komend dla powyższego breakpointu (zawsze dla ostatniego numeru)
commands $bpnum
    silent 
    diag1
end

# Uruchomienie programu
run
i b
n
diag1
s
diag1
