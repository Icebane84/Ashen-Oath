// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDynamicMusicSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenMusicState : uint8
{
	Exploration    UMETA(DisplayName = "Exploration"),
	CombatLight    UMETA(DisplayName = "CombatLight"),
	CombatIntense  UMETA(DisplayName = "CombatIntense"),
	BossFight      UMETA(DisplayName = "BossFight"),
	Sanctuary      UMETA(DisplayName = "Sanctuary"),
	Mindscape      UMETA(DisplayName = "Mindscape"),
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMusicStateChangedSignature, EAshenMusicState, OldState, EAshenMusicState, NewState);

/**
 * UAshenDynamicMusicSubsystem
 *
 * State-machine driven dynamic music system. Transitions between 6 music states
 * (Exploration, CombatLight, CombatIntense, BossFight, Sanctuary, Mindscape)
 * with a configurable 1.5s crossfade blend time. Prevents redundant transitions.
 */
UCLASS()
class ASHENOATH_API UAshenDynamicMusicSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Music")
	void TransitionToState(EAshenMusicState NewState);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Music")
	EAshenMusicState GetCurrentMusicState() const { return CurrentMusicState; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Music")
	float CrossfadeBlendTime = 1.5f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Music|Events")
	FOnMusicStateChangedSignature OnMusicStateChanged;

private:
	EAshenMusicState CurrentMusicState = EAshenMusicState::Exploration;
};
