// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenMartyrsPivotInterceptGASAbility.generated.h"

/**
 * UAshenMartyrsPivotInterceptGASAbility
 * Phase 2 struggle ability: executes protective lunge throw to intercept incoming lethal crush targeting companions.
 */
UCLASS()
class ASHENOATH_API UAshenMartyrsPivotInterceptGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenMartyrsPivotInterceptGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Struggle")
	float LungeDistanceUnits = 450.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Struggle")
	bool ExecuteProtectiveLunge(AActor* KaelenActor, AActor* ProtectedCompanionActor);
};
