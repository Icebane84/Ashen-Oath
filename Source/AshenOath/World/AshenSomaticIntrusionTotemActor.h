// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSomaticIntrusionTotemActor.generated.h"

/**
 * AAshenSomaticIntrusionTotemActor
 * World shrine amplifying companion resonance frequencies and unlocking advanced Nova finisher traits.
 */
UCLASS()
class ASHENOATH_API AAshenSomaticIntrusionTotemActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSomaticIntrusionTotemActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Nova")
	float ResonanceAuraRadius = 1500.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Nova")
	bool bIsTotemAwakened = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	bool AwakenTotem(AActor* InstigatingPlayer);
};
