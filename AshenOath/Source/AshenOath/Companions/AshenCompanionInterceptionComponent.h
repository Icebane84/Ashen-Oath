// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCompanionInterceptionComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnCompanionInterceptionTriggeredSignature, FName, InterceptorID, FVector, InterceptionPoint);

/**
 * UAshenCompanionInterceptionComponent
 *
 * Component executing Garrett/Serafina pre-emptive body-block interception when Kaelen is low health.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCompanionInterceptionComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenCompanionInterceptionComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|Interception")
	bool TriggerPreemptiveInterception(FName InterceptorID, FVector TargetDangerPoint);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Interception|Events")
	FOnCompanionInterceptionTriggeredSignature OnInterceptionTriggered;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|Interception")
	bool bInterceptionActive = false;
};
