#include "pch.h"

#include "CppUnitTest.h"
#include "../SMT/GeneralCodingProblems.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(UnitTests)
	{
	public:
		
#pragma region Test IsHomeRun


		/// <summary>
		/// Test case where wall is less than 1 unit too tall
		/// </summary>
		TEST_METHOD(TestMethod1)
		{
			const double exit_velocity = 220;
			const double launch_angle = 45;
			const double wall_height = 297;
			bool actual = false;
			IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsFalse(actual);
		}

		/// <summary>
		/// Test case where wall is less than 1 unit just short enough
		/// </summary>
		TEST_METHOD(TestMethod2)
		{
			const double exit_velocity = 220;
			const double launch_angle = 45;
			const double wall_height = 296;
			bool actual = false;
			IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsTrue(actual);
		}

		/// <summary>
		/// Test that ball shot straight up returns false flag
		/// </summary>
		TEST_METHOD(TestMethod3)
		{
			const double exit_velocity = 620;
			const double launch_angle = 90;
			const double wall_height = 6;
			bool actual = false;
			bool ran = IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsFalse(ran);
		}

		/// <summary>
		/// Test that TestMethod1 ran without errors
		/// </summary>
		TEST_METHOD(TestMethod4)
		{
			const double exit_velocity = 220;
			const double launch_angle = 45;
			const double wall_height = 297;
			bool actual = false;
			bool ran = IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsTrue(ran);
		}

		/// <summary>
		/// Test that with no wall, ball still doesn't reach past outfield
		/// </summary>
		TEST_METHOD(TestMethod5)
		{
			const double exit_velocity = 133;
			const double launch_angle = 22;
			const double wall_height = 0;
			bool actual = false;
			IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsFalse(actual);
		}

		/// <summary>
		/// Test that with no wall and increasing launch angle it will make it past outfield.
		/// </summary>
		TEST_METHOD(TestMethod6)
		{
			const double exit_velocity = 133;
			const double launch_angle = 24;
			const double wall_height = 0;
			bool actual = false;
			IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsTrue(actual);
		}

		/// <summary>
		/// Test that negative exit velocity returns false flag
		/// </summary>
		TEST_METHOD(TestMethod7)
		{
			const double exit_velocity = -133;
			const double launch_angle = 24;
			const double wall_height = 0;
			bool actual = false;
			bool ran = IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsFalse(ran);
		}

		/// <summary>
		/// Test that negative wall height returns false flag
		/// </summary>
		TEST_METHOD(TestMethod8)
		{
			const double exit_velocity = 133;
			const double launch_angle = 24;
			const double wall_height = -0.05;
			bool actual = false;
			bool ran = IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsFalse(ran);
		}

		/// <summary>
		/// Test that multiple invalid parameters returns false flag
		/// </summary>
		TEST_METHOD(TestMethod9)
		{
			const double exit_velocity = 133;
			const double launch_angle = -22;
			const double wall_height = -0.05;
			bool actual = false;
			bool ran = IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsFalse(ran);
		}

		/// <summary>
		/// Test that invalid negative launch_angle returns false flag
		/// </summary>
		TEST_METHOD(TestMethod10)
		{
			const double exit_velocity = 133;
			const double launch_angle = -90;
			const double wall_height = 10;
			bool actual = false;
			bool ran = IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsFalse(ran);
		}

		/// <summary>
		/// Test that 0 launch_angle returns true flag
		/// </summary>
		TEST_METHOD(TestMethod11)
		{
			const double exit_velocity = 133;
			const double launch_angle = 0;
			const double wall_height = 2;
			bool actual = false;
			bool ran = IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsTrue(ran);
		}

		/// <summary>
		/// Test that -370 hitting into ground does not make it over fence.
		/// </summary>
		TEST_METHOD(TestMethod12)
		{
			const double exit_velocity = 433;
			const double launch_angle = -370;
			const double wall_height = 0;
			bool actual = false;
			IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsFalse(actual);
		}

		/// <summary>
		/// Test case where launch angle cycles around unit circle
		/// </summary>
		TEST_METHOD(TestMethod13)
		{
			const double exit_velocity = 220;
			const double launch_angle = 45 + 360;
			const double wall_height = 296;
			bool actual = false;
			IsHomeRun(exit_velocity, launch_angle, wall_height, actual);
			Assert::IsTrue(actual);
		}
#pragma endregion Test IsHomeRun

#pragma region Test FindIntersectionDistance

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestMethod14)
		{
			const double camera_height = 3;
			const double camera_tilt = -45;
			double expected = 3;
			double actual;
			FindIntersectionDistance(camera_height, camera_tilt, actual);
			Assert::AreEqual(expected, actual, 0.001);
		}

		/// <summary>
		/// Test case
		/// </summary>
		TEST_METHOD(TestMethod15)
		{
			const double camera_height = 5;
			const double camera_tilt = -30;
			double expected = 8.66;
			double actual;
			FindIntersectionDistance(camera_height, camera_tilt, actual);
			Assert::AreEqual(expected, actual, 0.001);
		}

		/// <summary>
		/// Test case, test invalid camera height
		/// </summary>
		TEST_METHOD(TestMethod16)
		{
			const double camera_height = 0;
			const double camera_tilt = -30;
			double actual;
			bool ran = FindIntersectionDistance(camera_height, camera_tilt, actual);
			Assert::IsFalse(ran);
		}

		/// <summary>
		/// Test case, test invalid camera height
		/// </summary>
		TEST_METHOD(TestMethod17)
		{
			const double camera_height = -5;
			const double camera_tilt = -30;
			double actual;
			bool ran = FindIntersectionDistance(camera_height, camera_tilt, actual);
			Assert::IsFalse(ran);
		}

		/// <summary>
		/// Test case, test invalid camera tilt
		/// </summary>
		TEST_METHOD(TestMethod18)
		{
			const double camera_height = -5;
			const double camera_tilt = 0;
			double actual;
			bool ran = FindIntersectionDistance(camera_height, camera_tilt, actual);
			Assert::IsFalse(ran);
		}

		/// <summary>
		/// Test case camera looking directly at ground
		/// </summary>
		TEST_METHOD(TestMethod19)
		{
			const double camera_height = 5;
			const double camera_tilt = -90;
			double expected = 0;
			double actual;
			FindIntersectionDistance(camera_height, camera_tilt, actual);
			Assert::AreEqual(expected, actual, 0.001);
		}
#pragma endregion Test FindIntersectionDistance

#pragma region Test FindCameraHeight
		/// <summary>
		/// Test case 
		/// </summary>
		TEST_METHOD(TestMethod20)
		{
			const double field_length = 99;
			const double camera_field_of_view = 68;
			double expected = 73.3;
			double actual;
			FindCameraHeight(field_length, camera_field_of_view, actual);
			Assert::AreEqual(expected, actual, 0.1);
		}

		/// <summary>
		/// Test case flags
		/// </summary>
		TEST_METHOD(TestMethod21)
		{
			const double field_length = 0;
			const double camera_field_of_view = 68;
			double actual;
			bool ran = FindCameraHeight(field_length, camera_field_of_view, actual);
			Assert::IsFalse(ran);
		}

		/// <summary>
		/// Test case flags
		/// </summary>
		TEST_METHOD(TestMethod22)
		{
			const double field_length = 100;
			const double camera_field_of_view = 0;
			double actual;
			bool ran = FindCameraHeight(field_length, camera_field_of_view, actual);
			Assert::IsFalse(ran);
		}


		/// <summary>
		/// Test case flags
		/// </summary>
		TEST_METHOD(TestMethod23)
		{
			const double field_length = 100;
			const double camera_field_of_view = 180;
			double actual;
			bool ran = FindCameraHeight(field_length, camera_field_of_view, actual);
			Assert::IsFalse(ran);
		}


		/// <summary>
		/// Test case flags
		/// </summary>
		TEST_METHOD(TestMethod24)
		{
			const double field_length = 100;
			const double camera_field_of_view = 179.9;
			double actual;
			bool ran = FindCameraHeight(field_length, camera_field_of_view, actual);
			Assert::IsTrue(ran);
		}

#pragma endregion


	};
}
