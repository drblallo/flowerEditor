#include "treeLineObject.h"
#include <stack>

TreeLineObject::TreeLineObject(std::string source, float ang, float pers, float fd) : 
	angle(ang),
   	lines(makeLines(source, ang, pers, fd)),
   	ogg(&lines),
	persistance(pers),
	fade(fd)
{

}

struct LineCreationData
{
	public:
		QVector3D currentPos;
		QVector3D currentDirection;
		QVector3D currentColor;
		LineCreationData(QVector3D p, QVector3D dir, QVector3D col) :
		   	currentPos(p),
		   	currentDirection(dir),
			currentColor(col)
	{}
};

std::vector<Dot> TreeLineObject::makeLines(
		std::string &source,
	   	float ang,
	   	float persistance,
	   	float fade)
{
	std::vector<Dot> toReturn;
	LineCreationData currentData(QVector3D(0, 0, -10.0f), QVector3D(0, 1, 0), QVector3D(1, 1, 1));
	std::stack<LineCreationData> stk;

	for (unsigned a = 0; a < source.size(); a++)
	{
		if (source[a] == 'F')
		{
			toReturn.push_back(Dot(currentData.currentPos, currentData.currentColor));
			toReturn.push_back(Dot(currentData.currentPos + currentData.currentDirection, currentData.currentColor));
			currentData.currentPos += currentData.currentDirection;
		}
		if (source[a] == '[')
		{
			stk.push(currentData);
			currentData.currentDirection *= persistance;
			currentData.currentColor *= fade;
		}
		if (source[a] == ']')
		{
			currentData = stk.top();
			stk.pop();
		}
		if (source[a] == '+')
		{
			currentData.currentDirection = QQuaternion::fromEulerAngles(0, 0, ang) * currentData.currentDirection;
		}

		if (source[a] == '-')
		{
			currentData.currentDirection = QQuaternion::fromEulerAngles(0, 0, -1*ang) * currentData.currentDirection;
		}
	}	

	return toReturn;
}
