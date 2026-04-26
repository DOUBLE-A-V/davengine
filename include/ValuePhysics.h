class ValuePhysics {
private:
  float privateFriction;

public:
  ValuePhysics(float *valptr, float targetval);
  float changeSpeedRatio;
  float speedFloor;
  float speedCeil;
  float speed;
  float *valuePtr;
  float targetValue;
  float friction;
  float startVal;
  float overshooting;
  float outElasticRatio;
  void Update(float deltaTime);
};
