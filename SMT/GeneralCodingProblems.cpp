#include "pch.h";

#include "GeneralCodingProblems.h"
#define _USE_MATH_DEFINES
#include <cmath>

#pragma once

/// <summary>
/// Find height of camera to capture field in field of view
/// </summary>
/// <param name="field_length">Length of field to fully capture in units.</param>
/// <param name="camera_field_of_view">Camera field of view in degrees. Must be positive.</param>
/// <param name="camera_height">Height above field the camera is. Assumed orthogonal to field. In units.</param>
/// <returns></returns>
bool FindCameraHeight(const double field_length, const double camera_field_of_view, double& camera_height)
{
	if (field_length <= 0 || camera_field_of_view <= 0 || camera_field_of_view >= 180)
	{
		return false;
	}
	double half_field_length = field_length / 2;
	double half_camera_field_of_view_rads = camera_field_of_view / 2 * M_PI / 180;
	camera_height = half_field_length / std::tan(half_camera_field_of_view_rads);
	return true;
}

/// <summary>
/// Find the intersection distance of camera and ground plane
/// </summary>
/// <param name="camera_height">Expected positive. In units matching returned distance.</param>
/// <param name="camera_tilt">Must be between -90 and 0 </param>
/// <param name="distance"></param>
/// <returns>true if ran successfully, false if did not run successfully</returns>
bool FindIntersectionDistance(const double camera_height, const double camera_tilt, double& distance)
{
	if (camera_height <= 0 || !(camera_tilt < 0 && camera_tilt >= -90))
	{
		return false;
	}

	double camera_tilt_magnitude = std::abs(camera_tilt);
	double camera_tilt_rads = camera_tilt_magnitude * M_PI / 180;
	distance = camera_height / std::tan(camera_tilt_rads);
	return true;
}

/// <summary>
/// Calculates the vertical height of the ball at the outfield fence. Vertical height of the ball is measured from the bottom most point of the ball.
/// (Size of ball is not taken into account)
/// </summary>
/// <param name="exit_velocity">Velocity of hit. Expected greater than 0.</param>
/// <param name="launch_angle">Angle of hit. Handles negatives, as in the ball is hit towards the ground.</param>
/// <param name="wall_height">Assumed height from horizon to wall top, in units. Allows wall_height to be 0.</param>
/// <param name="is_homerun">If ball's vertical height is greater than the wall, return true, else false.</param>
/// <returns>true if ran successfully, false if did not run successfully</returns>
bool IsHomeRun(const double exit_velocity, const double launch_angle, const double wall_height, bool& is_homerun)
{
	is_homerun = false;
	double launch_angle_normalized = fmod(launch_angle, 360);

	if (exit_velocity <= 0 || !(launch_angle_normalized > -90 && launch_angle_normalized < 90) || wall_height < 0)
	{
		return false;
	}

	const double gravity_force = 32.2; // in units/(s^2)
	const double outfield_wall_distance = 400; // in units
	const double contact_height = 3; // in units
	double launch_angle_rads = launch_angle_normalized * M_PI / 180;
	double initial_velocity_x = exit_velocity * cos(launch_angle_rads);
	double initial_velocity_y = exit_velocity * sin(launch_angle_rads);

	// horizontal motion time formula
	// t = (x - x0) / vx
	if (initial_velocity_x == 0)
	{
		return false;
	}
	double time = outfield_wall_distance / initial_velocity_x;

	// vertical height of projectile formula:
	// y = y0 + v0y * t - (1/2)(g)(t^2)
	double ball_height_at_wall = contact_height + initial_velocity_y * time - (0.5) * gravity_force * time * time;
	
	is_homerun = ball_height_at_wall > wall_height;
	return true;
}