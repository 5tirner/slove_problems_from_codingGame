/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_of_the_tree.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zasabri <zasabri@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:28:38 by zasabri           #+#    #+#             */
/*   Updated: 2023/02/27 22:39:55 by zasabri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>

/*
in this probleme you need to calcul the height of a tree
you have only the distance and the angle_degree
example:
input:	distance = 10
		angle_degree = 10
		
output:	1
*/
int main() {
    int d, a_d;

    scanf("%d %d", &d, &a_d);
	double	a_rad, height;
    a_rad = a_d * 3.14 / 180;
    height = d * tan(a_rad);
    printf("%d", (int)height);
}