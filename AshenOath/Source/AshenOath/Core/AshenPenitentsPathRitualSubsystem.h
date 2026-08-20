// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenPenitentsPathRitualSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPenitentRitualCompletedSignature, FName, RitualID, bool, bAtoneSuccess);

/**
 * UAshenPenitentsPathRitualSubsystem
 *
 * Multi-stage ritual subsystem at Heartstone Crucibles for atoning for Scars of Corruption and Shadow Echoes.
 */
UCLASS()
class ASHENOATH_API UAshenPenitentsPathRitualSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PenitentRitual")
	bool BeginPenitentRitual(FName RitualID);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PenitentRitual")
	void CompletePenitentRitual(FName RitualID, bool bSuccess);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PenitentRitual|Events")
	FOnPenitentRitualCompletedSignature OnPenitentRitualCompleted;

private:
	FName ActiveRitualID;
};
