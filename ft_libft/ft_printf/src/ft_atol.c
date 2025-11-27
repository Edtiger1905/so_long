/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epandele <epandele@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:51:09 by epandele          #+#    #+#             */
/*   Updated: 2025/11/07 15:52:28 by epandele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/* Processa gli spazi iniziali e il segno.
 *
 * Questa funzione avanza l'indice *i nella stringa di input saltando
 * i caratteri di spaziatura (spazio e caratteri di controllo tra 9 e 13).

	* Poi controlla la presenza di un segno '+' o '-' e regola il segno
	di conseguenza.
 * Separare la gestione degli spazi e del segno in una funzione dedicata
 * migliora la modularità.
 *
 * *i è usato come puntatore a una variabile indice così che la funzione possa

	* aggiornare il valore dell'indice al di fuori del proprio scope.
	Questo permette

	* alla funzione di ricordare fino a che punto ha processato la stringa
	(saltando
 * spazi e gestendo il segno). */

static int	ft_handle_sign_and_spaces(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == 32 || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			sign *= -1;
		(*i)++;
	}
	return (sign);
}

/* Converte i caratteri numerici in una stringa in un long integer.
 *
 * Questa funzione legge i caratteri dalla stringa partendo dall'indice
 * puntato da *i, e accumula il loro valore numerico in un long.
 * Si ferma quando incontra un carattere non-cifra.
 *
 * La funzione controlla anche potenziali overflow:
 *   - Se viene rilevato un overflow e il segno è positivo,
 *     ritorna LONG_MAX.
 *   - Se negativo, ritorna LONG_MIN.
 *
 * Questo approccio modulare alla conversione numerica separa l'effettiva
 * logica di accumulo delle cifre dal parsing iniziale di segno e spazi.
 * Permette al processo di conversione di essere riutilizzato in altri contesti
 * gestendo l'overflow in maniera consistente. */

static long	ft_calculate_number(const char *str, int *i, int sign)
{
	long	result;

	result = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (result > (LONG_MAX - (str[*i] - '0')) / 10)
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (str[*i] - '0');
		(*i)++;
	}
	return (result);
}

/* Converte una stringa in un long integer.
 *
 * Questa funzione processa la stringa di input gestendo prima eventuali
 * spazi iniziali e il segno tramite ft_handle_sign_and_spaces(), poi calcola
 * il valore numerico usando ft_calculate_number(). Il risultato finale viene
 * ritornato con il segno appropriato applicato.
 *
 * Questa implementazione personalizzata di atol separa le responsabilità
 * della gestione del segno e degli spazi dalla conversione numerica. */

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = ft_handle_sign_and_spaces(str, &i);
	result = ft_calculate_number(str, &i, sign);
	return (result * sign);
}
