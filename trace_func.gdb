# Nie wyświetlamy potwierdzeń przy przeładowaniu
set confirm off
#set disassembly-flavor intel  # Opcjonalnie: format Intela jest czytelniejszy
define diag1
    printf "--- Diagnostyka Funkcji ---\n"
    # Wyświetla adres i plik/linię
    i args
    info line
     frame
    disassemble $pc, +40 
    printf "Adres w rejestrze PC: %p\n", $pc
    printf "---------------------------\n"
end

# Ustawiamy breakpoint na funkcji (zmień 'moja_funkcja' na docelową)
break sum_args

break sum_between_rec
# Definiujemy listę komend dla powyższego breakpointu (zawsze dla ostatniego numeru)
commands 1 2
silent 
diag1
end

# Uruchomienie programu
run
i b
c
c
c


set $i = 0
while($i++ < 10)
    p $i
    diag1
    c
end
