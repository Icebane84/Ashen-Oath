// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenShroudKnightBossActor.generated.h"

UENUM(BlueprintType)
enum class EAshenShroudKnightState : uint8
{
	Physical        UMETA(DisplayName = "Physical"),
	Phasing         UMETA(DisplayName = "Phasing"),
	Stunned         UMETA(DisplayName = "Stunned"),
	Defeated        UMETA(DisplayName = "Defeated")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnShroudKnightStateChangedSignature, EAshenShroudKnightState, OldState, EAshenShroudKnightState, NewState);

/**
 * AAshenShroudKnightBossActor
 *
 * Master Boss Actor for Greywatch Outpost Commander (The Shroud-Knight).
 * Features Physical/Phasing states, dither translucency opacity lerp, and CanPhaseShift() anchor checks.
 */
UCLASS()
class ASHENOATH_API AAshenShroudKnightBossActor : public ACharacter
{
	GENERATED_BODY()

public:
	AAshenShroudKnightBossActor();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|ShroudKnight")
	bool TryPhaseShift();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|ShroudKnight")
	void ForcePhysicalAnchor(bool bAnchorActive);

	UFUNCTION(BlueprintPure, Category = "AshenOath|ShroudKnight")
	bool CanPhaseShift() const;

	UFUNCTION(BlueprintPure, Category = "AshenOath|ShroudKnight")
	EAshenShroudKnightState GetKnightState() const { return CurrentState; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|ShroudKnight")
	float DitherOpacity = 1.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|ShroudKnight|Events")
	FOnShroudKnightStateChangedSignature OnStateChanged;

private:
	EAshenShroudKnightState CurrentState = EAshenShroudKnightState::Physical;
	bool bIsAnchoredByConsecratedGround = false;
	bool bIsPinLockedByKaelen = false;
};
