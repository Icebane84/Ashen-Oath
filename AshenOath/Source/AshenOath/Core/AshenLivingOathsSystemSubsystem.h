// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenLivingOathsSystemSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLivingOathStateChangedSignature, FName, OathPactID, bool, bIsBound);

/**
 * UAshenLivingOathsSystemSubsystem
 *
 * World Subsystem tracking active Living Oaths ("Protective Vow", "Vengeance Pact") granting party-wide combat buffs.
 */
UCLASS()
class ASHENOATH_API UAshenLivingOathsSystemSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|LivingOaths")
	bool BindLivingOath(FName OathPactID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|LivingOaths")
	void BreakLivingOath(FName OathPactID);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|LivingOaths|Events")
	FOnLivingOathStateChangedSignature OnLivingOathStateChanged;

private:
	TSet<FName> ActiveBoundOaths;
};
