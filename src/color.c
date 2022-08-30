#define GAMMA 0.43

// Returns a linear value in the range [0,1]
// for sRGB input in [0,255].
double	ChannelInvCompanding(int c)
{
	double y;

	c = c & 0xFF;
	y = (double) c;
	y = y / 255.0;
	if (c <= 0.04045)
		y = y / 12.92;
	else
		y = pow(((y + 0.055) / 1.055), 2.4);
	return (y);
}

// Convert color from 0..255 to 0..1
// Inverse Srgb Companding for Red, Green, and Blue
double	*InverseSrgbCompanding(int c)
{
	double  *r = malloc(4 * sizeof(double));

	r[0] = (double) get_t(c);
	r[1] = ChannelInvCompanding(get_r(c));
	r[2] = ChannelInvCompanding(get_g(c));
	r[3] = ChannelInvCompanding(get_b(c));

	return (r);
}

// Apply companding to Red, Green, and Blue
double	ChannelCompanding(double c)
{
	double x;

	if (c <= 0.0031308)
		x = 12.92 * c;
	else
		x = (1.055 * pow(c, (1/2.4))) - 0.055;
	return (x);
}

// return new color. Convert 0..1 back into 0..255
// Srgb Companding for Red, Green, and Blue
int	SrgbCompanding(double *c)
{
	int t;
	int r;
	int g;
	int b;

	t = (int)c[0];
	r = (int)(ChannelCompanding(c[1]) * 255);
	g = (int)(ChannelCompanding(c[2]) * 255);
	b = (int)(ChannelCompanding(c[3]) * 255);
	free(c);
	return (create_trgb(t, r, g, b));
}

// sums channels
// does not include transperancy
double	sumChannels(double *c)
{
	double x = c[1] + c[2] + c[3];
	return (x);
}

// Lerping see
// https://en.wikipedia.org/wiki/Linear_interpolation
// #Programming_language_support
double	lerp_int(double c1, double c2, double t)
{
	return (c1 * (1 - t) + c2 * t);
	//return ((1 - t) * c1 + t * c2);
}

double	*lerp(double *c1, double *c2, double t)
{
	double  *r = malloc(4 * sizeof(double));

	//r[1] = ((1 - t) * c1[1] + t * c2[1]);
	//r[2] = ((1 - t) * c1[2] + t * c2[2]);
	//r[3] = ((1 - t) * c1[3] + t * c2[3]);
	r[1] = (c1[1] * (1 - t)) + c2[1] * t;
	r[2] = (c1[2] * (1 - t)) + c2[2] * t;
	r[3] = (c1[3] * (1 - t)) + c2[3] * t;
	return (r);
}

typedef struct s_bresvars {
	int x;
	int y;
	int dx;
	int dy;
	int s1;
	int s2;
	int swap;
	int temp;
	int d;
	int i;
}   t_bresvars;



int	sign(int x)
{
	if (x > 0)
		return (1);
	else if (x < 0)
		return (-1);
	else
		return (0);
}


void	bresenhams_alg(int x1, int y1, int x2, int y2, int scolor, int ecolor, t_vars *vars)
{
	double step;
	double *color;
	double intensity;
	double total;
	int temp;
	int d;
	int clr;

	double *color1_lin = InverseSrgbCompanding(scolor);
	double bright1 = pow(sumChannels(c.color1_lin), GAMMA);
	double *color2_lin = InverseSrgbCompanding(ecolor);
	double bright2 = pow(sumChannels(c.color2_lin), GAMMA);

	int x = x1;
	int y = y1;
	int dx = abs(x2 - x1); 
	int dy = abs(y2 - y1);
	int s1 = sign(x2 - x1); 
	int s2 = sign(y2 - y1);
	int swap = 0;
	int i = 0;
	double step_c = 0;

	if (dy > dx) {
		temp = dx;
		dx = dy;
		dy = temp;
		swap = 1;
	}

	d = 2*dy - dx;
	step = (1.0 / dx);
	while (i < dx)
	{
		step_c += step;
		intensity = pow(lerp_int(bright1, bright2, step), (1 / GAMMA));
		color = lerp(color1_lin, color2_lin, step);
		total = sumChannels(color);
		if (total != 0)
			c[1] = (c[1] * intensity / total);
		c[2] = (c[2] * intensity / total);
		c[3] = (c[3] * intensity / total);
		clr = SrgbCompanding(color);
		pixel_put(x, y, clr);
		while (v.d >= 0)
		{
			v.d = v.d - 2 * v.dx;
			if (v.swap)
				v.x += v.s1;
			else
				v.y += v.s2;
		}
		v.d = v.d + 2 * v.dy;
		if (v.swap)
			v.y += v.s2;
		else
			v.x += v.s1;
		v.i++;
	}
	free(color1_lin);
	free(color2_lin);
}
