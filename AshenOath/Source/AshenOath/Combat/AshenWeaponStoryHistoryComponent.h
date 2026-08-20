// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWeaponStoryHistoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeaponStoryMarkRecordedSignature, FName, BattleMarkTag, float, SootIntensity);

/**
 * UAshenWeaponStoryHistoryComponent
 *
 * Component recording weapon scars, soot marks, and crossguard repairs onto weapon meshes.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenWeaponStoryHistoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenWeaponStoryHistoryComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeaponHistory")
	void RecordBattleMark(FName BattleMarkTag, float SootIntensity = 0.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeaponHistory|Events")
	FOnWeaponStoryMarkRecordedSignature OnMarkRecorded;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WeaponHistory")
	TArray<FName> RecordedBattleMarks;
};
