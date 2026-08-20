// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenTabardRaggednessClothDriver.generated.h"

/**
 * UAshenTabardRaggednessClothDriver
 * Component driving real-time geometric tearing (alpha scissor discard) and cloth charring on Kaelen's tabard during Dark Mode transitions.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenTabardRaggednessClothDriver : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenTabardRaggednessClothDriver();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Shader Driver")
	float ClothTabardOpacityScalar = 1.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Shader Driver")
	void ApplyTabardRaggednessParameters(float RaggednessMask);
};
