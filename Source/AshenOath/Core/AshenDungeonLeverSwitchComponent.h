// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonLeverSwitchComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnLeverToggledSignature, FName, LeverID, bool, bIsActivated);

/**
 * UAshenDungeonLeverSwitchComponent
 *
 * Interactive dungeon lever switch component managing activation state and puzzle door trigger events.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonLeverSwitchComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonLeverSwitchComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Lever")
	bool ToggleLever();

	UFUNCTION(BlueprintPure, Category = "AshenOath|Lever")
	bool IsActivated() const { return bIsActivated; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Lever")
	FName LeverID = FName("Lever_Default");

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Lever|Events")
	FOnLeverToggledSignature OnLeverToggled;

private:
	bool bIsActivated = false;
};
