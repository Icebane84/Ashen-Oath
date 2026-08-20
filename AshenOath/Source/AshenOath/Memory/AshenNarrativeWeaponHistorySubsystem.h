// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenNarrativeWeaponHistorySubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeaponHistoryRecordedSignature, FName, WeaponID, int32, TotalKillsRecorded);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeaponRuneInscribedSignature, FName, RuneGlyphID, int32, InscribedTier);

/**
 * UAshenNarrativeWeaponHistorySubsystem
 * Tracks parries, executions, and weapon kill imprints, dynamically inscribing glowing runes onto Kaelen's weapon.
 */
UCLASS()
class ASHENOATH_API UAshenNarrativeWeaponHistorySubsystem : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeaponHistory|Events")
	FOnWeaponHistoryRecordedSignature OnWeaponHistoryRecorded;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeaponHistory|Events")
	FOnWeaponRuneInscribedSignature OnWeaponRuneInscribed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WeaponHistory")
	int32 TotalOathbringerKills = 0;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|WeaponHistory")
	int32 TotalWeaponExecutions = 0;

	UPROPERTY(BlueprintReadOnly, Category = "AshenOath|WeaponHistory")
	int32 InscribedRuneTiers = 0;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeaponHistory")
	void RecordWeaponKillImprint(FName WeaponID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeaponHistory")
	void RecordExecutionKill(FName VictimType);
};
