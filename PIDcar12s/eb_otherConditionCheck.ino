

void conditions_manager()
{
  if (otherconditionsCheck())
  {
    myledwhiteon();
    otherconditionsDO();
    Taction = millis();
    otherconditionsCounter++;
    pathSteps++;
  }
  else
    ELSE();
}
boolean otherconditionsCheck()
{

  switch (otherconditionsCounter)
  {


      break;
    case 0:
      // Serial.println(" Condition 1 check ");
      // return CountLines() >= 2 ;
      return compare(IntDsensors, "xx11111111xx") ;

      break;
    case 1:
      Serial.println(" Condition 3 check ");
      //
      return (CountLines() >= 2 || compare(IntDsensors, "1x111x000000"));
      break;
    case 2:
      Serial.println(" Condition 4 check ");

      return  CountLines() >= 2 ;
      break;

    case 3:
      Serial.println(" Condition 3 check ");
      //return    compare(IntDsensors, "1x111x000000") ;
      return  (compare(IntDsensors, "xx11111111xx"));
      break;

    case 4:
      Serial.println(" Condition 5 check ");
      return  CountLines() >= 2  ;
      break;
    case 5:
      Serial.println(" Condition 5 check ");
      return compare(IntDsensors, "111111111111");
      break;
//    case 6:
//      Serial.println(" Condition 5 check ");
//      return CountLines() >= 2;
//      break;
//    case 7:
//      Serial.println(" Condition 5 check ");
//      return true ;
//      break;
    case 6:
      Serial.println(" Condition 5 check ");
      return CountLines() >= 2;
      break;
    case 7:
      Serial.println(" Condition 5 check ");
      return CountLines() >= 2;
      break;
    case 8:
      Serial.println(" Condition 5 check ");
      return compare(IntDsensors, "111111111111");
      break;
    case 9:
      Serial.println(" Condition 5 check ");
      return (CountLines() >= 2 || compare(IntDsensors, "111111100000") );
      break;
    case 10:
      Serial.println(" Condition 5 check ");
      return ( compare(IntDsensors, "111111111111") );
      break;
    // ADD CASES IF U HAVE MORE
    default:
      Serial.println("Error! NOMBER OF C IN PATHSTRING IS MORE THAN THE CONDITIONS IN otherconditionsCheck FUNCTION");
      return true; // to continue following and does get stuck
  }
  return false; // if anything missing in the conditions bech lcode may7bsch
}
