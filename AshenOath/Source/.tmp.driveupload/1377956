// Copyright Phoenix Protocol. All rights reserved.

#include "AshenDamageTextActor.h"
#include "Components/TextRenderComponent.h"

AAshenDamageTextActor::AAshenDamageTextActor()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	TextRender = CreateDefaultSubobject<UTextRenderComponent>(TEXT("TextRender"));
	RootComponent = TextRender;

	// Center-align text
	TextRender->SetHorizontalAlignment(EHorizTextAligment::EHTA_Center);
	TextRender->SetVerticalAlignment(EVerticalTextAligment::EVRTA_TextCenter);
	TextRender->SetWorldSize(32.0f);
	TextRender->SetTextRenderColor(FColor::Red);

	MaxLifetime = 1.0f;
	FloatSpeed = 120.0f; // float speed units/second
	Lifetime = 0.0f;
	bIsActive = false;
}

void AAshenDamageTextActor::BeginPlay()
{
	Super::BeginPlay();
	Deactivate();
}

void AAshenDamageTextActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsActive) return;

	Lifetime += DeltaTime;

	// Move text upward
	AddActorWorldOffset(FVector(0.0f, 0.0f, FloatSpeed * DeltaTime));

	// Calculate alpha fadeout
	float Alpha = 1.0f - (Lifetime / MaxLifetime);
	FColor TextColor = TextRender->TextRenderColor;
	TextColor.A = FMath::Clamp(FMath::FloorToInt(Alpha * 255.0f), 0, 255);
	TextRender->SetTextRenderColor(TextColor);

	if (Lifetime >= MaxLifetime)
	{
		Deactivate();
	}
}

void AAshenDamageTextActor::Activate(float Amount, FVector StartPos)
{
	SetActorLocation(StartPos);
	TextRender->SetText(FText::AsNumber(FMath::RoundToInt(Amount)));
	
	FColor TextColor = TextRender->TextRenderColor;
	TextColor.A = 255;
	TextRender->SetTextRenderColor(TextColor);

	SetActorHiddenInGame(false);
	SetActorTickEnabled(true);

	Lifetime = 0.0f;
	bIsActive = true;
}

void AAshenDamageTextActor::Deactivate()
{
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	bIsActive = false;
}
