/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esellier <esellier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 11:32:45 by ineimatu          #+#    #+#             */
/*   Updated: 2025/03/05 13:32:33 by esellier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3D.h"

void next_vertical(t_data * data, double x_a, double b_y, double b_x, double radians)
{
    double a_y;
    int i;
    i = 0;
    a_y = fabs(TILE * tan(radians));
    if (ray_projected_up(data->ray.angle_start) == 1)
        a_y *= -1;
    /*printf("%i vertical x increment = %f\n", i, x_a);
    printf("%i vertical y increment = %f\n", i,  a_y);
    printf("Angle %f\n", data->ray.angle_start);*/
    while (1)
    {
        b_x += x_a;
        b_y += a_y;
        /*if (data->ray.angle_start > 260 && data->ray.angle_start < 280)
        {
            printf("%i hit x = %f\n", i, b_x);
            printf("%i hit y = %f\n", i,  b_y);
            printf("Coordinates [%i], [%i]\n", (int)b_y / TILE, (int)b_x / TILE);
        }*/
        /*if (check_diagonal(data->map->matrix, data, (int)b_x / TILE, (int)b_y / TILE) == 1)
        {
            data->ray.dist_v = data->ray.dist_v + 0.0000000001;
            break;
        }*/
        if ((int)b_y / TILE >= 0 && (int)b_x / TILE >= 0 && b_x / TILE < check_length(data->map->matrix, (int)(b_y / TILE)))
        {
            if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE])
            {
                if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == '1' || data->map->matrix[(int)b_y / TILE][(int)b_x / TILE ] == 'D')
                {
                    if (data->map->matrix[(int)(b_y / TILE)][(int)(b_x / TILE)] == 'D')
                        data->ray.type = 'd';
                    else
                        data->ray.type = 'w';
                    data->ray.dist_v = find_distance_v(data, b_x, b_y);
                    break;
                }
            }
            i++;
        }
        else
        {
            //printf("Error in next_vertical, out of the map\n");
            //data->ray.dist_v = DBL_MAX;
            data->ray.dist_v = find_distance_v(data, b_x, b_y);
            break;
        }
    }
}
void vertical_check(t_data *data, double radians)
{
    double b_x;
    double b_y;
    double x_a;
    b_x = floor(data->ray.player_x / TILE);
    b_x *= TILE;
    x_a = TILE;
    if (ray_projected_left(data->ray.angle_start) == 1)
    {
        b_x -= 0.00001;;
        x_a *= -1;
    }
    else
    {
        b_x += TILE;
    }
    b_y = data->ray.player_y + (data->ray.player_x - b_x) * tan(radians);
    /*if (data->ray.angle_start > 260 && data->ray.angle_start < 280)
    {
        printf("\n\n\nVERTICAL CHECK\n\n\n");
        printf("First hit x = %f\n", b_x);
        printf("Position x jugador = %f, position y = %f, resultado tan = %f\n", data->ray.player_y, data->ray.player_x, tan(radians));
        printf("First hit y = %f\n", b_y);
        printf("Coordinates [%i], [%i]\n", (int)b_y / TILE, (int)b_x / TILE);
        printf("angle view = %f\n", radians * 180.0 / PI);
        printf("tan radians = %f\n", tan(radians));
    }*/
    if ((int)b_y / TILE > 0 && (int)b_x / TILE >= 0)
    {
        if (b_x / TILE < check_length(data->map->matrix, (int)(b_y / TILE)))
        {
        //printf("%i\n", height(data, fabs(b_x / TILE), b_y / TILE));
/*&& data->ray.map_y > (int)b_y / TILE && data->map->matrix[(int)b_y / TILE][(int)b_x / TILE]*/
            if (data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == '1' || data->map->matrix[(int)b_y / TILE][(int)b_x / TILE] == 'D')
            {
                if (data->map->matrix[(int)(b_y / TILE)][(int)(b_x / TILE)] == 'D')
                        data->ray.type = 'd';
                    else
                        data->ray.type = 'w';
                data->ray.dist_v = find_distance_v(data, b_x, b_y);
                //if (fabs(data->ray.old_distance_v - data->ray.dist_v) > 1)
                //  printf("PROBLEME\n");
                //data->ray.old_distance_v = data->ray.dist_v;
            }
            else
                next_vertical(data, x_a, b_y, b_x, radians);
        }
    }
    else
    {
        data->ray.dist_v = find_distance_v(data, b_x, b_y);
        //printf("Out of map on vertical check\n");
        //data->ray.dist_v = DBL_MAX;
    }
}
void    next_checks(t_data *data, double a_x, double a_y, double radians)
{
    double y_a;
    double x_a;
    double c_x;
    double c_y;
    int i;
    i = 0;
    y_a = TILE;
    if (ray_projected_up(data->ray.angle_start) == 1)
        y_a *= -1;
    x_a = fabs(TILE/tan(radians));
    if (ray_projected_left(data->ray.angle_start) == 1)
        x_a *= -1;
    /*printf("%i horizontal x increment = %f\n", i, x_a);
    printf("%i horizontal y increment = %f\n", i,  y_a);
    printf("Angle %f\n", data->ray.angle_start);*/
    while (1)
    {
        c_x = a_x + x_a;
        c_y = a_y + y_a;
        /*printf("%i hit x = %f\n", i, c_x);
        printf("%i hit y = %f\n", i,  c_y);
        printf("Coordinates [%i], [%i]\n", (int)c_y / TILE, (int)c_x / TILE);*/
        /*if (check_diagonal(data->map->matrix, data, (int)c_x / TILE, (int)c_y / TILE) == 1)
        {
            data->ray.dist_h = data->ray.dist_h;
            break ;
        }*/
        if ((int)c_y / TILE >= 0 && (int)c_x / TILE >= 0 && c_x / TILE < check_length(data->map->matrix, (int)(c_y / TILE)))
        {
            //if (data->map->matrix[(int)(c_y / TILE)][(int)c_x / TILE - 1])
            //{
                if (data->map->matrix[(int)(c_y / TILE)][(int)(c_x / TILE)] == '1' || data->map->matrix[(int)(c_y / TILE)][(int)(c_x / TILE)] == 'D')
                {
                    if (data->map->matrix[(int)(c_y / TILE)][(int)(c_x / TILE)] == 'D')
                        data->ray.type = 'd';
                    else
                        data->ray.type = 'w';
                    data->ray.dist_h = find_distance_h(data, c_x, c_y);
                    break;
                }
                a_x = c_x;
                a_y = c_y;
                i++;
            //}
            //else
            //  break;
        }
        else
        {
            data->ray.dist_h = find_distance_h(data, c_x, c_y);
            //data->ray.dist_h = DBL_MAX;
            break;
        }
    }
}
void horizontal_check(t_data *data, double radians)
{
    double a_y;
    double a_x;
    a_y = floor(data->ray.player_y / TILE);
    a_y *= TILE;
    if (ray_projected_up(data->ray.angle_start) == 1)
        a_y = a_y - 0.001;
    else
        a_y += TILE;
    a_x = data->ray.player_x + (data->ray.player_y - a_y) / tan(radians);
    // if (data->ray.angle_start > 260 && data->ray.angle_start < 280)
    // {
    //     printf("\n\nHORIZONTAL CHECK\n\n\n");
    //     //printf("player x = %f\n", data->ray.player_x);
    //     printf("player y in the map = %f\n", data->player.position_y);
    //     printf("player x in the map = %f\n", data->player.position_x);
    //     //printf("player y = %f\n", data->ray.player_y);
    //     printf("First hit x = %f\n", a_x);
    //     printf("First hit y = %f\n", a_y);
    //     printf("angle view = %f\n", radians * 180.0 / PI);
    //     printf("Coordinates [%i], [%i]\n", (int)a_y / TILE, (int)a_x / TILE);
    // }
    if ((int)a_y / TILE >= 0 && (int)a_x / TILE >= 0 && a_x / TILE < check_length(data->map->matrix, (int)(a_y / TILE)))
    {
        //if (data->map->matrix[(int)a_y / TILE][(int)a_x / TILE])
            //if (a_y % (a_y * 2))
            if (data->map->matrix[(int)(a_y / TILE)][(int)(a_x / TILE)] == '1' || data->map->matrix[(int)(a_y / TILE)][(int)(a_x / TILE)] == 'D')
            {
                    if (data->map->matrix[(int)(a_y / TILE)][(int)(a_x / TILE)] == 'D')
                        data->ray.type = 'd';
                    else
                        data->ray.type = 'w';
                    data->ray.dist_h = find_distance_h(data, a_x, a_y);
                    //if (fabs(data->ray.old_distance_v - data->ray.dist_h) > 1)
                    //  printf("PROBLEME\n");
                    //data->ray.old_distance_v = data->ray.dist_h;
            }
            else
                next_checks(data, a_x, a_y, radians);
        //}
    }
    else
    {
        data->ray.dist_h = find_distance_h(data, a_x, a_y);
        //printf("Out of map\n");
        //data->ray.dist_h = DBL_MAX;
    }
}
void    init_ray(t_data *data)
{
    data->ray.fov = 60;
    //data->player.position_x = 24.535243;
    //data->player.position_y = 5.992807;
    data->ray.player_x = ((double)data->player.position_x * 64);
    data->ray.player_y = ((double)data->player.position_y * 64);
    //printf("player x = %f\n", data->ray.player_x);
    //printf("player y = %f\n", data->ray.player_y);
    data->ray.angle_start = (double)data->player.angle + (data->ray.fov / 2);
    if (data->ray.angle_start > 360)
        data->ray.angle_start -= 360;
    data->ray.angle_end = (double)data->player.angle - (data->ray.fov / 2);
    if (data->ray.angle_end < 0)
        data->ray.angle_end = 360 + data->ray.angle_end;
    data->ray.wall_hit = 'c';
    data->ray.h_x = 0;
    data->ray.v_x = 0;
    data->ray.h_y = 0;
    data->ray.v_y = 0;
    data->ray.hit_x = 0;
    data->ray.hit_y = 0;
    //data->ray.old_distance_v = 0;
}
double  adjust_angle(double angle)
{
    double res;
    res = 0;
    res = fmod(angle, 360.0);
    if (res <= 0.0)
        res = res + 360.0;
    return (res);
}
void    ray_trace(t_data *data, int x, double increment)
{
    double radians;
    data->ray.angle_start = adjust_angle(data->ray.angle_start);
    radians = data->ray.angle_start * (M_PI / 180.0);
    horizontal_check(data, radians);
    vertical_check(data, radians);
    find_shortest_distance(data);
    wall_height(data, x);
    increment = (double)data->ray.fov / LENGTH;
    data->ray.angle_start -= increment;
}
void    find_wall(t_data *data)
{
    int x;
    double increment;
    x = 0;
    increment = (double)data->ray.fov / (double)LENGTH;
    init_ray(data);
    if (data->ray.angle_start == 90)
    {
        data->ray.angle_start -= 2.2;
        data->ray.angle_end -= 2.2;
    }
    while (x <= LENGTH)
    {
        ray_trace(data, x, increment);
        x++;
    }
    mlx_put_image_to_window(data->mlx, data->mlx_window, data->image->img_add, 0, 0);
    do_mini_map(data, data->map->matrix);
}