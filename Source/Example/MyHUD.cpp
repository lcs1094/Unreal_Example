// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Engine/Engine.h"
#include "Engine/Canvas.h"
#include "Example.h"
#include "Avatar.h"

void AMyHUD::DrawHUD() {
	Super::DrawHUD();
	for (int c = messages.Num() - 1; c >= 0; c--) {
		float outputWitdh, outputHeight, pad = 1.0f;
		GetTextSize(messages[c].message, outputWitdh, outputHeight, hudFont, 1.f);
		float messageH = outputHeight + 2.f * pad;
		float x = 0.f, y = c * messageH;
		DrawRect(FLinearColor::Black, x, y, Canvas->SizeX, messageH);
		DrawText(messages[c].message, messages[c].color, x + pad, y + pad, hudFont);
		messages[c].time -= GetWorld()->GetDeltaSeconds();
		if (messages[c].time < 0) {
			messages.RemoveAt(c);
		}
	}
}

void AMyHUD::addMessage(Message msg) {
		messages.Add(msg);
}