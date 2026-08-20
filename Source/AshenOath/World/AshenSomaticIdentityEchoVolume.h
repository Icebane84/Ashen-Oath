// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "AshenSomaticIdentityEchoVolume.generated.h"

/**
 * AAshenSomaticIdentityEchoVolume
 * Spatial volume component emitting somatic identity echo fields and psychological distortion scalars.
 */
UCLASS()
class ASHENOATH_API AAshenSomaticIdentityEchoVolume : public AVolume
{
	GENERATED_BODY()

public:
	AAshenSomaticIdentityEchoVolume();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | World")
	float IdentityEchoIntensity = 0.85f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void ApplyIdentityEchoToActor(AActor* TargetActor);
};
