void otherconditionsDO()
{

  if (otherconditionsCounter == 0)
  {
    turn(-80);
    SetPoint = 10000;
    // forward(100,100);
    //delay(70);

  }


  else if (otherconditionsCounter == 1)
  {
    turn(90);
    SetPoint = 5500;

  }

  else if (otherconditionsCounter == 2)

  {

    left(140, 100);
    delay(250);
    while (1)
    {
      left(60, 60); // ////Serial.println("right");
      updatesensors(currentLineColor);
      if ( ((CountLines() == 1) && (position < 4000) && (position > 1000) ))
        break;
    }

  }
  else if (otherconditionsCounter == 3)
  {


    forward(140, 140);
    delay(300);




    //
    //    double salim = millis();
    //    if ((millis() - salim) > 500||(compare(IntDsensors, "x111111xxxx0"))) {
    //      myledwhiteon();
    //      turn(-90);
    //    }
  }


  //
  //    turn(130);
  //    left(80,60);
  //    delay(140);
  ////    back();
  ////    delay(150);
  ////    stope();
  ////    delay(60);
  //    offD = OfflineDirection::Disabled;
  //
  //    forward(140, 140);
  //    delay(350);
  //
  //    while (true) {
  //      forward(100, 100);
  //      updatesensors(currentLineColor);
  //      if (CountLines() == 1 )
  //      {
  //
  //        break;
  //      }
  //
  //
  //    }
  //}
  else   if (otherconditionsCounter == 4)
  {

    turn(55);

  }






  //    int oldDistance = distanceL;
  //    // getAngle();
  //    double  lastAngle = GyroAngle;
  //    initialAngle = GyroAngle;
  //    //initialAngle=initialAngle - 360;
  //    back();
  //    delay(50);
  //    stope();
  //    delay(500);
  //    double entryTime = millis();
  //    while (true) {
  //      forward(100, 110);
  //      updatesensors(currentLineColor);
  //      if (((distanceF < 17) && (distanceL < 17)) || ((millis() - entryTime ) > 2000)) break;
  //    }
  //    turn(-50);
  //    stope();
  //    while (1) {
  //      oldDistance = distanceL;
  //      // getAngle();
  //      lastAngle = GyroAngle;
  //      wallfollow(18, 'L');
  //      if (((millis() - entryTime) > 4000) && (lastAngle - initialAngle > 70 ) && (distanceL  > 50)) {
  //        right();
  //        delayGyro(50);
  //        stope();
  //        delayGyro(300);
  //        forward(100, 100);
  //        delayGyro(400);
  //        back();
  //        delayGyro(50);
  //        stope();
  //        turn(initialAngle + 110);
  //        delayGyro(200);
  //        entryTime = millis();
  //        while (1) {
  //          forward(100, 100);
  //          updatesensors(currentLineColor);
  //          if ((distanceL > 60 && millis() - entryTime > 50) || millis() - entryTime > 320) break;
  //        }
  //        forward(100, 100);
  //        delayGyro(120);
  //        stope();
  //        turn(initialAngle + 180);
  //        entryTime = millis();
  //        while (true) {
  //          forward(100, 100);
  //          updatesensors(currentLineColor);
  //          if (distanceF < 17 || millis() - entryTime > 900) break;
  //        }
  //        back();
  //        delay(50);
  //        stope();
  //        delay(100000);
  //      }
  //    }


  else if (otherconditionsCounter == 5)
  {

   
   forward(200,200);
   delay(100);


  }
//  else if (otherconditionsCounter == 6)
//  { turn(60);
//    direction = WhichLineToFollow::RIGHT;
//    //SetPoint = 2500;
//
//    //  if(compare(IntDsensors, "xx11111111xx"))
//    //  {
//    //    forward(100, 100);
//    //    delay(140);
//    //    }
//
//
//  }
//  else if (otherconditionsCounter == 7)
//  {
//    direction = WhichLineToFollow::AUTO;
//    //SetPoint = 5500;
//
//  }
  else if (otherconditionsCounter == 6)
  {
    turn(-36);
    forward(110, 150);
    delay(120 );

  }
  else if (otherconditionsCounter == 7)
  {


    forward(140, 140);
    delay(200 );
  }
  else if (otherconditionsCounter == 8)
  {

    back();
    delay(150);
    stope();
    delay(5000);

  }

  else if (otherconditionsCounter == 9)
  {

    turn(10);
    right();
    delay(100);

  }
  else if (otherconditionsCounter == 10)
  {

    back(200, 200);
    delay(80);
    stope();
    delay(50000);


  }









  //    back(); delay(50); stope(); delay(50);
  //
  //    forward(120, 120);
  //    delay(150);
  //    double t = millis();
  //    while ((millis() - t) < 300) {
  //      updatesensors(currentLineColor);
  //      forward(150, 150);
  //      if (distanceF < 5);
  //      turn(-100);
  //      break;
  //    }
  //
  //    forward(150, 150);
  //    delay(700);
  //    while (1) {
  //      forward(110, 110);
  //      wallfollow(12, 'R', false);
  //      if ((distanceF < 8) and (distanceL > 40) ) {
  //        turn(100);
  //        break;
  //      }
  //    }
  //
  //    while (1) {
  //      forward(100, 100);
  //      wallfollow(10, 'R', false);
  //      if ((distanceF < 15) && (distanceL > 40)) {
  //        turn(90);
  //        break;
  //      }
  //      back(); delay(50); stope(); delay(50);
  //    }
  //
  //    while (1) {
  //      forward(120, 120);
  //      wallfollow(12, 'R', false);
  //      if ((distanceF < 11) && (distanceL > 40)) {
  //        turn(-95);
  //        break;
  //      }
  //    }
  else Serial.println("Error! NOMBER OF C IN PATHSTRING IS MORE THAN THE CONDITIONS IN otherconditionsDO FUNCTION");

}
