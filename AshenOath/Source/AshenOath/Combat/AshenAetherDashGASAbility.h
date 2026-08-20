// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenAetherDashGASAbility.generated.h"

/**
 * UAshenAetherDashGASAbility
 * Omnidirectional traversal dash covering 800.0uu in 0.25s, granting invulnerability frames and dispersing local hazard clouds.
 */
UCLASS()
class ASHENOATH_API UAshenAetherDashGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenAetherDashGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Traversal")
	float DashDistance = 800.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Traversal")
	float DashDuration = 0.25f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Traversal")
	float StaminaCost = 25.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Traversal")
	bool PerformAetherDash(AActor* InstigatorActor, const FVector& InputDirection);
};
