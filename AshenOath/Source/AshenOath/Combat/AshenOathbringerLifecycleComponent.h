// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "AshenOathbringerLifecycleComponent.generated.h"

class UAshenSoulPublisher;

UENUM(BlueprintType)
enum class EOathbringerLifecycleState : uint8
{
	Dormant     UMETA(DisplayName = "Dormant (Heavy Iron Slab / High Drag, Mass = 120kg)"),
	Predictive  UMETA(DisplayName = "Predictive (Flow State / Seamless Handling, Mass = 45kg)"),
	Autonomous  UMETA(DisplayName = "Autonomous (Shadow Pull / Unchained Velocity, Mass = 0kg, +400uu/s)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnOathbringerLifecycleChangedSignature, EOathbringerLifecycleState, NewState, float, EffectiveMass, FLinearColor, EmissiveColor);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGuardSocketInscribedSignature, EOathbringerMartialStance, Guard, FName, MemoryEchoID);

/**
 * UAshenOathbringerLifecycleComponent
 *
 * Implements the 3-Stage Weapon Lifecycle (Dormant -> Predictive -> Autonomous)
 * and 4-Guard Fuller Seam Runic Loci Socket Inscription, coupled atomically
 * to UAshenSoulPublisher (CONVERGENCE-SPEC-101 / PRS-001 Combat Manifesto V5.0).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerLifecycleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerLifecycleComponent();

	virtual void BeginPlay() override;

	/** Evaluates weapon lifecycle from SSoT FSoulStateVector */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Oathbringer")
	EOathbringerLifecycleState EvaluateWeaponLifecycle();

	/** Inscribes an unsealed Memory Echo into one of the 4 Liechtenauer guard sockets */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Oathbringer")
	bool InscribeMemoryEchoToGuardSocket(EOathbringerMartialStance Guard, FName MemoryEchoID);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	EOathbringerLifecycleState GetCurrentLifecycleState() const { return CurrentLifecycle; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	float GetEffectiveWeaponMass() const { return EffectiveMass; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	float GetForwardPullImpulse() const { return ForwardPullImpulse; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	FLinearColor GetGuardSocketEmissiveColor(EOathbringerMartialStance Guard) const;

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	FName GetSocketInscribedEcho(EOathbringerMartialStance Guard) const;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Oathbringer|Events")
	FOnOathbringerLifecycleChangedSignature OnLifecycleChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Oathbringer|Events")
	FOnGuardSocketInscribedSignature OnGuardSocketInscribed;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Oathbringer")
	EOathbringerLifecycleState CurrentLifecycle = EOathbringerLifecycleState::Dormant;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Oathbringer")
	float EffectiveMass = 120.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Oathbringer")
	float ForwardPullImpulse = 0.0f;

private:
	TMap<EOathbringerMartialStance, FName> GuardSocketMap;
	UAshenSoulPublisher* GetSoulPublisher() const;
};
