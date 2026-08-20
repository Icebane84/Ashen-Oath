// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 698: Ashen Garrett Triple Dagger Fan Ability

#include "AshenGarrettTripleDaggerFanAbility.h"

void UAshenGarrettTripleDaggerFanAbility::ExecuteTripleDaggerFan(float BaseDamagePerDagger)
{
	const int32 DaggerCount = 3;
	const float TotalDamage = BaseDamagePerDagger * DaggerCount;

	OnDaggerFanExecuted.Broadcast(DaggerCount, TotalDamage);

	UE_LOG(LogTemp, Warning, TEXT("UAshenGarrettTripleDaggerFanAbility: TRIPLE DAGGER FAN EXECUTED -> Daggers: %d | Total Radial Damage: %.1f HP."),
		DaggerCount, TotalDamage);
}
