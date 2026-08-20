// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAegisHalfSwordBraceComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnHalfSwordBraceExecutedSignature, float, StaminaDrained, float, ChipDamageTaken);

/**
 * UAshenAegisHalfSwordBraceComponent
 *
 * Component executing Standard Block (Half-Sword Brace) absorbing titanic strikes with heavy stamina drain & minor chip damage (PRS-001 Combat Blueprint V5.0).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAegisHalfSwordBraceComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenAegisHalfSwordBraceComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|AegisBrace")
	void ExecuteHalfSwordBrace(float IncomingDamage = 150.0f);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|AegisBrace|Events")
	FOnHalfSwordBraceExecutedSignature OnHalfSwordBraceExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|AegisBrace")
	bool bIsBracing = false;
};
