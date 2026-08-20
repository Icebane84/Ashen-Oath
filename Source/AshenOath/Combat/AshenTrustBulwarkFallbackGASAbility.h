// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenTrustBulwarkFallbackGASAbility.generated.h"

/**
 * UAshenTrustBulwarkFallbackGASAbility
 * Trust choice ability: pivots Kaelen into Serafina's bulwark, spiking trust by +3.5, clearing 5% debt, and opening an 8s Resonant Window.
 */
UCLASS()
class ASHENOATH_API UAshenTrustBulwarkFallbackGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenTrustBulwarkFallbackGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float TrustMatrixSpike = 3.5f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float ResonantWindowDurationSeconds = 8.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool ExecuteTrustFallback(AActor* KaelenActor, AActor* SerafinaActor);
};
