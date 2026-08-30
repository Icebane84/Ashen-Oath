// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenOathbringerStanceTypes.h"
#include "Combat/AshenOathbringerMetallurgyTypes.h"
#include "AshenOathbringerLifecycleComponent.generated.h"

class UAshenSoulPublisher;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnOathbringerMetallurgyChangedSignature, EOathbringerMetallurgicalTier, NewTier, float, EffectiveMass, FOathbringerMaterialParameters, MaterialParams, FOathbringerAcousticProfile, AcousticProfile);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGuardSocketInscribedSignature, EOathbringerMartialStance, Guard, FName, MemoryEchoID);

/**
 * UAshenOathbringerLifecycleComponent
 *
 * Implements the 5-Tier Grounded Metallurgy, PBR Material Parameters, and Light-Absorption
 * Physics for Oathbringer (METALLURGY-SPEC-102 / CONVERGENCE-SPEC-101 / Anti-Arcade Law).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOathbringerLifecycleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOathbringerLifecycleComponent();

	virtual void BeginPlay() override;

	/** Evaluates metallurgical tier from SSoT FSoulStateVector */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Oathbringer")
	EOathbringerMetallurgicalTier EvaluateWeaponLifecycle();

	/** Inscribes an unsealed Memory Echo into one of the 4 Liechtenauer guard sockets */
	UFUNCTION(BlueprintCallable, Category = "Ashen Oath|Oathbringer")
	bool InscribeMemoryEchoToGuardSocket(EOathbringerMartialStance Guard, FName MemoryEchoID);

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	EOathbringerMetallurgicalTier GetCurrentMetallurgicalTier() const { return CurrentTier; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	float GetEffectiveWeaponMass() const { return EffectiveMass; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	float GetForwardPullImpulse() const { return ForwardPullImpulse; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	FOathbringerMaterialParameters GetActiveMaterialParameters() const { return MaterialParameters; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	FOathbringerAcousticProfile GetActiveAcousticProfile() const { return AcousticProfile; }

	UFUNCTION(BlueprintPure, Category = "Ashen Oath|Oathbringer")
	FName GetSocketInscribedEcho(EOathbringerMartialStance Guard) const;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Oathbringer|Events")
	FOnOathbringerMetallurgyChangedSignature OnMetallurgyChanged;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Oathbringer|Events")
	FOnGuardSocketInscribedSignature OnGuardSocketInscribed;

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Oathbringer")
	EOathbringerMetallurgicalTier CurrentTier = EOathbringerMetallurgicalTier::BurdenedIron;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Oathbringer")
	float EffectiveMass = 120.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Oathbringer")
	float ForwardPullImpulse = 0.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Oathbringer")
	FOathbringerMaterialParameters MaterialParameters;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ashen Oath|Oathbringer")
	FOathbringerAcousticProfile AcousticProfile;

private:
	TMap<EOathbringerMartialStance, FName> GuardSocketMap;
	UAshenSoulPublisher* GetSoulPublisher() const;
};
