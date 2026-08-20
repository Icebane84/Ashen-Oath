// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenMartyrGuardAllyInterceptComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnMartyrGuardInterceptExecutedSignature, AActor*, ProtectedAlly, float, InterceptStaminaCost);

/**
 * UAshenMartyrGuardAllyInterceptComponent
 *
 * Component intercepting lethal blows aimed at companions at stamina/corruption cost (The Martyr's Guard).
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMartyrGuardAllyInterceptComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMartyrGuardAllyInterceptComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|MartyrGuard")
	void InterceptLethalBlowForAlly(AActor* ProtectedAlly, float DamageToIntercept);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|MartyrGuard|Events")
	FOnMartyrGuardInterceptExecutedSignature OnInterceptExecuted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|MartyrGuard")
	int32 TotalLethalInterceptsExecuted = 0;
};
