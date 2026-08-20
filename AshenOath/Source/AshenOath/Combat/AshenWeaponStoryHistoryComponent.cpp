// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
// Build 609: Ashen Weapon Story History Component

#include "AshenWeaponStoryHistoryComponent.h"

UAshenWeaponStoryHistoryComponent::UAshenWeaponStoryHistoryComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	RecordedBattleMarks.Empty();
}

void UAshenWeaponStoryHistoryComponent::RecordBattleMark(FName BattleMarkTag, float SootIntensity)
{
	if (BattleMarkTag.IsNone()) return;

	RecordedBattleMarks.AddUnique(BattleMarkTag);
	OnMarkRecorded.Broadcast(BattleMarkTag, SootIntensity);

	UE_LOG(LogTemp, Warning, TEXT("UAshenWeaponStoryHistoryComponent: BATTLE MARK RECORDED -> '%s' (Soot Intensity: %.2f | Total Marks: %d)."),
		*BattleMarkTag.ToString(), SootIntensity, RecordedBattleMarks.Num());
}
