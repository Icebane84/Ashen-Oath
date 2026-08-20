// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenHalfSwordBraceStanceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHalfSwordBraceImpactSignature, float, AbsorbedDamage, bool, bPreventedKnockdown);

/**
 * UAshenHalfSwordBraceStanceComponent
 *
 * Component managing Half-Sword Brace stance absorption against behemoth knockdowns.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenHalfSwordBraceStanceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenHalfSwordBraceStanceComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|HalfSwordBrace")
	void AbsorbBehemothImpact(float IncomingDamage);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|HalfSwordBrace|Events")
	FOnHalfSwordBraceImpactSignature OnBraceImpact;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|HalfSwordBrace")
	bool bIsBracingActive = false;
};
