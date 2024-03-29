#include "main.h"
#include "parse_scene/ps_parse_textures.h"
#include "parse_scene/ps_utils.h"
#include "utils/u_.h"

static void	parse_plane(t_object *object, char **line)
{
	*line += 2;
	object->type = PLANE;
	object->center = parse_xyz(line, MIN_XYZ, MAX_XYZ);
	object->orientation = parse_orientation(line);
	object->is_cap = true;
}

static void	parse_sphere(t_object *object, char **line)
{
	*line += 2;
	object->type = SPHERE;
	object->center = parse_xyz(line, MIN_XYZ, MAX_XYZ);
	object->radius = parse_float(line, MIN_DIAMETER, MAX_DIAMETER) / 2;
	object->is_cap = false;
}

static void	parse_cylinder(t_object *object, char **line)
{
	*line += 2;
	object->type = CYLINDER;
	object->center = parse_xyz(line, MIN_XYZ, MAX_XYZ);
	object->orientation = parse_orientation(line);
	object->radius = parse_float(line, MIN_DIAMETER, MAX_DIAMETER) / 2;
	object->height = parse_float(line, MIN_CY_HEIGHT, MAX_CY_HEIGHT);
	object->is_cap = false;
}

static void	parse_cone(t_object *object, char **line)
{
	*line += 2;
	object->type = CONE;
	object->center = parse_xyz(line, MIN_XYZ, MAX_XYZ);
	object->orientation = parse_orientation(line);
	object->radius = parse_float(line, MIN_DIAMETER, MAX_DIAMETER) / 2;
	object->height = parse_float(line, MIN_CY_HEIGHT, MAX_CY_HEIGHT);
	object->is_cap = false;
}

void	parse_objects(t_mlx *mlx, char *line)
{
	int	i;

	if (mlx->object_count >= MAX_OBJECTS)
		error_message_and_exit("Too many objects in scene");
	i = mlx->object_count;
	if (str_is_equal(line, "pl", 2))
		parse_plane(&mlx->object[i], &line);
	if (str_is_equal(line, "sp", 2))
		parse_sphere(&mlx->object[i], &line);
	if (str_is_equal(line, "cy", 2))
		parse_cylinder(&mlx->object[i], &line);
	if (str_is_equal(line, "co", 2))
		parse_cone(&mlx->object[i], &line);
	mlx->object[i].is_inside = false;
	mlx->object[i].color = parse_xyz(&line, MIN_COLOR, MAX_COLOR);
	mlx->object[i].specular = 0;
	mlx->object[i].specular = parse_float(&line, MIN_SPECULAR, MAX_SPECULAR);
	mlx->object[i].reflective = 0;
	mlx->object[i].reflective
		= parse_float(&line, MIN_REFLECTIVE, MAX_REFLECTIVE);
	parse_textures(&mlx->object[i], &line);
	mlx->object[i].t = RAY_T_MAX;
	mlx->object_count += 1;
}
