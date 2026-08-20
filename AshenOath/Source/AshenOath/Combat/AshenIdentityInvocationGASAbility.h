// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenIdentityInvocationGASAbility.generated.h"

/**
 * UAshenIdentityInvocationGASAbility
 * Gameplay Ability triggering CompileIdentity() at the Heartstone — the ritual invocation flushing the imprint buffer and publishing the new state vector.
 */
UCLASS()
class ASHENOATH_API UAshenIdentityInvocationGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenIdentityInvocationGASAbility();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | GAS")
	bool bForcedCollapse = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | GAS")
	bool InvokeIdentityCompilationAtHeartstone();
};
