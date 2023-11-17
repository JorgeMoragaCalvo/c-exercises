     .data
msg1: .asciiz "Ingrese el primer numero: "
msg2: .asciiz "Ingrese el segundo numero: "
msg3: .asciiz "La multiplicacion es: "
msg4: .asciiz "La division es: "
msg5: .asciiz "El resto es: "
msg6: .asciiz "Resultado de 0.1 es: "
newline: .asciiz "\n"
float_value_one: .float 0.1
float_value_two: .float 0.01

    .text
    .globl main

main:
    # Reservar espacio en la pila para las variables locales
    addi $sp, $sp, -8
    
    # Cargar flotantes
    lwc1 $f0, float_value_one
    lwc1 $f1, float_value_two

    # Imprimir "Ingrese el primer numero: "
    li $v0, 4
    la $a0, msg1
    syscall

    # Leer el primer numero (a)
    li $v0, 5
    syscall
    move $s0, $v0  # Guardar el primer numero en $s0

    # Imprimir "Ingrese el segundo numero: "
    li $v0, 4
    la $a0, msg2
    syscall

    # Leer el segundo numero (b)
    li $v0, 5
    syscall
    move $s1, $v0  # Guardar el segundo numero en $s1

    # Llamar a la función mulSum
    move $a0, $s0  # Pasar a como primer argumento
    move $a1, $s1  # Pasar b como segundo argumento
    jal mulSum     # Llamar a mulSum
    move $s2, $v0  # Guardar el resultado en $s2

    # Imprimir "El resultado es: " para mulSum
    li $v0, 4
    la $a0, msg3
    syscall

    # Imprimir el resultado de mulSum
    move $a0, $s2
    li $v0, 1
    syscall

    # Imprimir un salto de línea
    li $v0, 4
    la $a0, newline
    syscall

    # Llamar a la función dividend
    move $a0, $s0  # Pasar a como primer argumento
    move $a1, $s1  # Pasar b como segundo argumento
    jal dividend   # Llamar a dividend
    move $s3, $v0  # Guardar el resultado en $s3

    # Imprimir "El resultado es: " para dividend
    li $v0, 4
    la $a0, msg4
    syscall

    # Imprimir el resultado de dividend
    move $a0, $s3
    li $v0, 1
    syscall

    # Imprimir un salto de línea
    li $v0, 4
    la $a0, newline
    syscall

    # Llamar a la función remain
    move $a0, $s0  # Pasar a como primer argumento
    move $a1, $s1  # Pasar b como segundo argumento
    jal remain     # Llamar a remain
    move $s4, $v0  # Guardar el resultado en $s4

    # Imprimir "El resultado es: " para remain
    li $v0, 4
    la $a0, msg5
    syscall

    # Imprimir el resultado de remain
    move $a0, $s4
    li $v0, 1
    syscall
    
    jal mulSumFloat
    
    # Imprimir un salto de línea
    li $v0, 4
    la $a0, newline
    syscall
    
    # Imprimir "El resultado es: " para remain
    li $v0, 4
    la $a0, msg6
    syscall
    
    #Imprimir resultado mulSumFloat
    li $v0, 2
    add.s $f12, $f3, $f0
    syscall

    # Salir del programa
    li $v0, 10
    syscall

# Función mulSum(a, b)
mulSum:
    # Prologo de la función
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    # Inicializar la suma en 0
    li $t0, 0  # $t0 se usará para sum

    # Inicializar el contador i en 0
    li $t1, 0  # $t1 se usará para i

    loop_mulSum:
        # Comprobar si i < b
        bge $t1, $a1, end_mulSum

        # sum = sum + a
        add $t0, $t0, $a0

        # Incrementar i
        addi $t1, $t1, 1

        j loop_mulSum

    end_mulSum:
        # Retornar el valor de la suma
        move $v0, $t0

        # Epilogo de la función
        lw $ra, 0($sp)
        addi $sp, $sp, 4
        jr $ra

# Función dividend(a, b)
dividend:
    # Prologo de la función
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    # Inicializar el acumulador en 0
    li $t0, 0  # $t0 se usará para accu

    # Comprobar si a < b
    blt $a0, $a1, end_dividend

    loop_dividend:
        # Comprobar si a >= b
        bge $a0, $a1, continue_dividend

        j end_dividend

    continue_dividend:
        # a = a - b
        sub $a0, $a0, $a1

        # Incrementar el acumulador
        addi $t0, $t0, 1

        j loop_dividend

    end_dividend:
        # Retornar el valor del acumulador
        move $v0, $t0

        # Epilogo de la función
        lw $ra, 0($sp)
        addi $sp, $sp, 4
        jr $ra

# Función remain(a, b)
remain:
    # Prologo de la función
    addi $sp, $sp, -4
    sw $ra, 0($sp)

    loop_remain:
        # Comprobar si a >= b
        bge $a0, $a1, continue_remain

        j end_remain

    continue_remain:
        # a = a - b
        sub $a0, $a0, $a1

        j loop_remain

    end_remain:
        # Retornar el valor final de a
        move $v0, $a0

        # Epilogo de la función
        lw $ra, 0($sp)
        addi $sp, $sp, 4
        jr $ra

mulSumFloat:
    # Procedimiento para multiplicar y sumar
    # Argumentos: $f0 (float a), $s0 (int b)
    # Resultado: $f0 (resultado)

    # Inicializar $f2 a 0.0 (usando $f2 para la variable result)
    lwc1 $f2, 0($sp)  # Carga el valor previo de $f0 guardado en la pila
    #mov.s $f2, $f0

    # Inicializar contador $t0 = 0
    li $t0, 0

    loop:
        # Verificar si $t0 >= $s0
        bge $t0, $s1, end_loop

        # Sumar $f0 a $f2
        add.s $f2, $f2, $f0

        # Incrementar $t0
        addi $t0, $t0, 1

        # Ir al inicio del loop
        j loop

    end_loop:
        # Guardar el resultado en $f0 y volver
        mov.s $f0, $f2
        jr $ra