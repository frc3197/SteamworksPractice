#include <map>

#include "WPILib.h"
#include "ctre/Phoenix.h"


class Robot: public frc::IterativeRobot {
public:
	void RobotInit() {

	}

	void TeleopPeriodic() {
//		drive.DriveCartesian(s.GetRawAxis(5), s.GetRawAxis(4), s.GetRawAxis(1));

//		shoot.Set((a.Get()) ? 1 : 0);
//		aug.Set(())
	}

private:

	std::map<std::string, int> m = { { "fr", 3 }, { "fl", 4 }, { "br", 2 },
			{ "bl", 1 }, {"shoot", 9}, {"aug", 10}};

	WPI_TalonSRX fr{m["fr"]};
	WPI_TalonSRX fl{m["fl"]};
	WPI_TalonSRX br{m["br"]};
	WPI_TalonSRX bl{m["bl"]};

	MecanumDrive drive{fr, fl, br, bl};

	WPI_TalonSRX shoot{m["shoot"]};
	WPI_TalonSRX aug{m["aug"]};

	Joystick s{0};

	JoystickButton a{&s, 1};
	JoystickButton b{&s, 2};
	JoystickButton x{&s, 3};
	JoystickButton y{&s, 4};


};

START_ROBOT_CLASS(Robot)
