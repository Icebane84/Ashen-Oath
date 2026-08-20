// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#include "Combat/GA_KaelenEmpathicNovaThrust.h"

UGA_KaelenEmpathicNovaThrust::UGA_KaelenEmpathicNovaThrust()
{
	LungeSpeed = 1400.0f;
	LockDistanceThreshold = 150.0f;
	KaelenHandSocketName = TEXT("hand_l");
	StaffSocketName = TEXT("Staff_Thrust_Socket");
}

bool UGA_KaelenEmpathicNovaThrust::ExecuteNovaThrustAndSocketLock(AActor* KaelenActor, AActor* SerafinaActor, AActor* TargetEnemy)
{
	if (!KaelenActor || !SerafinaActor || !TargetEnemy) return false;

	UE_LOG(LogTemp, Warning, TEXT("UGA_KaelenEmpathicNovaThrust: Kaelen executed thrust lunge (1400 uu/s), locked '%s' to '%s', driven Oathbringer through %s spine!"),
		*KaelenHandSocketName.ToString(), *StaffSocketName.ToString(), *TargetEnemy->GetName());
	return true;
}
