// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AshenWhispererEnemy.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWhispererShadowPhaseSignature, bool, bIsPhasedIn, float, SanityDamagePerSec);

/**
 * AAshenWhispererEnemy
 *
 * AI Enemy class for psychological Whisperer shadow entities.
 */
UCLASS()
class ASHENOATH_API AAshenWhispererEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	AAshenWhispererEnemy();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Whisperer")
	void TriggerShadowPhase(bool bPhaseIn);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Whisperer|Events")
	FOnWhispererShadowPhaseSignature OnShadowPhaseChanged;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Whisperer")
	bool bIsPhasedIn = true;
};
