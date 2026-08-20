// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "AshenGameplayAbility.h"
#include "AshenSanctuaryAnchorGASAbility.generated.h"

/**
 * UAshenSanctuaryAnchorGASAbility
 * Serafina's reality-stabilizing ability creating a zone of ordered reality to anchor phasing Void predators into physical vulnerability.
 */
UCLASS()
class ASHENOATH_API UAshenSanctuaryAnchorGASAbility : public UAshenGameplayAbility
{
	GENERATED_BODY()
public:
	UAshenSanctuaryAnchorGASAbility();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Ashen Oath | Combat")
	float AnchorDurationSeconds = 6.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool CreateSanctuaryAnchor(AActor* InstigatorActor, const FVector& AnchorLocation);
};
