// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenResonantArmamentsSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnArmamentEnchantedSignature, FName, ArmamentID, FName, ImprintedMemoryID);

/**
 * UAshenResonantArmamentsSubsystem
 *
 * Equipment enchanting subsystem allowing "Solidified Memories" to be imprinted onto weapons/armor for passive resonance effects.
 */
UCLASS()
class ASHENOATH_API UAshenResonantArmamentsSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ResonantArmaments")
	bool ImprintMemoryOnArmament(FName ArmamentID, FName MemoryID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ResonantArmaments|Events")
	FOnArmamentEnchantedSignature OnArmamentEnchanted;

private:
	TMap<FName, FName> ImprintedArmaments;
};
