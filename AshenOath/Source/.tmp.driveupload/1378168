// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAegisWhiteFlameDefensiveComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenAegisDefensiveStance : uint8
{
	None              UMETA(DisplayName = "None"),
	GlancingDeflect   UMETA(DisplayName = "Glancing Deflection (Perfect Parry)"),
	HalfSwordBrace    UMETA(DisplayName = "Half-Sword Brace (Standard Block)"),
	CrownGuardCounter UMETA(DisplayName = "Crown Guard Counter-Bind"),
	MartyrGuard       UMETA(DisplayName = "Martyr's Guard (Ally Intercept)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAegisStanceActivatedSignature, EAshenAegisDefensiveStance, ActiveStance, float, StaminaCost);

/**
 * UAshenAegisWhiteFlameDefensiveComponent
 *
 * Defensive Component for Oathbringer implementing Aegis of the White Flame defensive stances (PRS-001 Combat Blueprint).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAegisWhiteFlameDefensiveComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAegisWhiteFlameDefensiveComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AegisDefensive")
	void ActivateDefensiveStance(EAshenAegisDefensiveStance TargetStance);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AegisDefensive|Events")
	FOnAegisStanceActivatedSignature OnStanceActivated;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisDefensive")
	EAshenAegisDefensiveStance CurrentStance = EAshenAegisDefensiveStance::None;
};
