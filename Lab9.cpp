//This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <http://www.gnu.org/licenses/>.
#include "Lab9.h"

char addToSelection(void)
{
	char c;
	cout << endl;
	cout << "Add Object to Selection:" << endl;
	cout << "1) Rectangle" << endl;
	cout << "2) Triangle" << endl;
	cout << "3) Circle" << endl;
	cout << "0) Done" << endl;
	cout << "Selection: ";
	cin >> c;
	cout << endl;
	return c;
}

int main(void)
{
	char c = '1';
	vector<Shape *> s;
	vector<Shape *>::iterator i;
	Shape *t;
	while(c != '0')
	{
		c = addToSelection();
		switch(c)
		{
			case '1':
				t = new Rectangle();
				break;
			case '2':
				t = new Triangle();
				break;
			case '3':
				t = new Circle();
				break;
			default:
				c = '0';	// Make any other key an exit signal.
				break;
		}
		if(c != '0')
		{
			t->getParameters();
			s.push_back(t);
		}
	}
	if(s.size() > 0)
		cout << "Computing all areas..." << endl << endl;
	for(i = s.begin(); i < s.end(); i++)
	{
		t = *i;	// Reuse the temporary shape to point to object.
		t->calcArea();
		t->printArea();
		delete t;	// Clean up the objects as we iterate through the list
	}
	cout << endl << "Thank you for using the calculator." << endl << endl;
	return 0;
}
