#include <map>

#include "WPILib.h"
#include "ctre/Phoenix.h"

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() override {
		climberFollow.Follow(climber);
		shoot.SetInverted(true);
	}

	void TeleopPeriodic() override {
		drive.DriveCartesian(s.GetRawAxis(5), -s.GetRawAxis(4), -s.GetRawAxis(0));

		shoot.Set(s.GetRawAxis(2));
		intake.Set(s.GetRawAxis(3));

		climber.Set((a.Get()) ? 1 : 0);
		aug.Set((lb.Get()) ? .35 : (rb.Get()) ? -.35 : 0);
	}

private:

	std::map<std::string, int> m = { { "fr", 3 }, { "fl", 4 }, { "br", 2 }, {
			"bl", 1 }, { "intake", 6 }, { "climber", 7 },
			{ "climberFollow", 8 }, { "shoot", 9 }, { "aug", 10 } };

	WPI_TalonSRX fr { m["fr"] };
	WPI_TalonSRX fl { m["fl"] };
	WPI_TalonSRX br { m["br"] };
	WPI_TalonSRX bl { m["bl"] };

	MecanumDrive drive { fr, fl, br, bl };

	WPI_TalonSRX shoot { m["shoot"] };
	WPI_TalonSRX aug { m["aug"] };
	WPI_TalonSRX intake { m["intake"] };
	WPI_TalonSRX climber { m["climber"] };
	WPI_TalonSRX climberFollow { m["climberFollow"] };

	Joystick s { 0 };

	JoystickButton a { &s, 1 };
	JoystickButton lb { &s, 5 };
	JoystickButton rb { &s, 6 };
//	JoystickButton b{&s, 2};
//	JoystickButton x{&s, 3};
//	JoystickButton y{&s, 4};
};

START_ROBOT_CLASS(Robot)
