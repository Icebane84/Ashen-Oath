// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "GA_SerafinaEmpathicConduitNova.generated.h"

/**
 * UGA_SerafinaEmpathicConduitNova
 * Serafina's Empathic Conduit Nova ability.
 * Gated behind Burnout >= 0.70f, channels accumulated trauma into enemy core and resets burnout to 0%.
 */
UCLASS()
class ASHENOATH_API UGA_SerafinaEmpathicConduitNova : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UGA_SerafinaEmpathicConduitNova();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Conduit Nova | Settings")
	float SyncRange = 1200.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Conduit Nova | Settings")
	float BaseNovaDamage = 750.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen | Conduit Nova | Settings")
	float NovaRadius = 600.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen | Conduit Nova | Execution")
	bool InitiateConduitChannel(AActor* SerafinaActor, AActor* KaelenActor, AActor* TargetEnemy, float ActiveBurnout);
};
